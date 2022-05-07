/*
 * @Author: Chacha
 * @Date: 2022-05-07 11:47:52
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-05-07 16:06:32
 */

/**
 * 来源：https://leetcode-cn.com/problems/jump-game-ii/
 *
 * 45. 跳跃游戏 II
 *
 * 给你一个非负整数数组 nums ，你最初位于数组的第一个位置。数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。假设你总是可以到达数组的最后一个位置。
 *
 * 示例 1:
 * 输入: nums = [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 *
 * 示例 2:
 * 输入: nums = [2,3,0,1,4]
 * 输出: 2
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
    int jump(vector<int> &nums);
};

/**
 * 方法：贪心算法，正向查找可到达的最大位置
 *
 * 思路：如果我们「贪心」地进行正向查找，每次找到可到达的最远位置，就可以在线性时间内得到最少的跳跃次数。
 *
 * 例如，对于数组 [2,3,1,2,4,2,3]，初始位置是下标 0，从下标 0 出发，最远可到达下标 2。
 * 下标 0 可到达的位置中，下标 1 的值是 3，从下标 1 出发可以达到更远的位置，因此第一步到达下标 1。
 * 从下标 1 出发，最远可到达下标 4。下标 1 可到达的位置中，下标 4 的值是 4 ，从下标 4 出发可以达到更远的位置，因此第二步到达下标 4。
 *
 * 如图 ./jump_game_ii.png
 *
 * 在具体的实现中，我们维护当前能够到达的最大下标位置，记为边界。我们从左到右遍历数组，到达边界时，更新边界并将跳跃次数增加 1。
 *
 * 在遍历数组时，我们不访问最后一个元素，这是因为在访问最后一个元素之前，我们的边界一定大于等于最后一个位置，
 * 否则就无法跳到最后一个位置了。如果访问最后一个元素，在边界正好为最后一个位置的情况下，
 * 我们会增加一次「不必要的跳跃次数」，因此我们不必访问最后一个元素。
 *
 * 时间复杂度：O(n)，其中 n 是数组长度。
 * 空间复杂度：O(1)。
 *
 * 题解：https://leetcode-cn.com/problems/jump-game-ii/solution/tiao-yue-you-xi-ii-by-leetcode-solution/
 *
 */
int Solution::jump(vector<int> &nums)
{
    int maxPos = 0;      // 目前能跳到的最远位置
    int n = nums.size(); // 数组长度
    int step = 0;        // 跳跃次数
    int end = 0;         // 上次跳跃可达范围右边界（下次的最右起跳点）

    for (int i = 0; i < n - 1; i++)
    {
        if (maxPos >= i)
        {
            maxPos = max(maxPos, i + nums[i]);

            if (i == end)
            {
                end = maxPos;
                step++;
            }
        }
    }

    return step;
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {2, 3, 1, 2, 4, 2, 3};
    vector<int> nums1 = {2, 3, 1, 1, 4};

    cout << "nums = [2, 3, 1, 2, 4, 2, 3], 最少的跳跃次数为: " << s.jump(nums) << endl;
    cout << "\nnums = [2, 3, 1, 1, 4], 最少的跳跃次数为: " << s.jump(nums1) << endl;

    return 0;
}
