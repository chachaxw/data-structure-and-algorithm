/*
 * @Author: Chacha
 * @Date: 2022-04-25 16:10:12
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-25 16:40:37
 */

/**
 * 来源：https://leetcode-cn.com/problems/jump-game/
 *
 * 55. 跳跃游戏
 *
 * 给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 判断你是否能够到达最后一个下标。
 *
 * 示例 1：
 * 输入：nums = [2,3,1,1,4]
 * 输出：true
 * 解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
 *
 * 示例 2：
 * 输入：nums = [3,2,1,0,4]
 * 输出：false
 * 解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
 *
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    /* data */
public:
    bool canJump(vector<int> &nums);
};

/**
 * 方法：贪心算法
 *
 * 思路：
 * 刚看到本题一开始可能想：当前位置元素如果是3，我究竟是跳一步呢，还是两步呢，还是三步呢，究竟跳几步才是最优呢？
 * 其实跳几步无所谓，关键在于可跳的覆盖范围！不一定非要明确一次究竟跳几步，每次取最大的跳跃步数，这个就是可以跳跃的覆盖范围。
 * 这个范围内，别管是怎么跳的，反正一定可以跳过来。那么这个问题就转化为跳跃覆盖范围究竟可不可以覆盖到终点！
 *
 * 贪心算法局部最优解：每次取最大跳跃步数（取最大覆盖范围），整体最优解：最后得到整体最大覆盖范围，看是否能到终点。
 *
 * 如图：
 *
 * 下标i：    0    1    2    3    4            0    1    2    3    4
 *           3    2    1    0    4            2    3    1    1    4
 *
 * cover:    ---------------                  -----------
 *                ----------                       ----------------
 *                     -----
 *             cover 仅覆盖了下标 3                  cover 能覆盖下标 4
 *
 *
 */
bool Solution::canJump(vector<int> &nums)
{
    int cover = 0;

    if (nums.size() == 1)
    {
        return true; // 只有一个元素就能到达
    }

    for (int i = 0; i <= cover; i++)
    {
        cover = max(i + nums[i], cover);

        if (cover >= nums.size() - 1)
        {
            return true;
        }
    }

    return false;
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {3, 2, 1, 0, 4};
    vector<int> nums1 = {2, 3, 1, 1, 4};

    cout << "nums = [2,3,1,1,4], 是否能够到达最后一个下标? " << s.canJump(nums) << endl;
    cout << "\nnums = [3,2,1,0,4], 是否能够到达最后一个下标? " << s.canJump(nums1) << endl;

    return 0;
}
