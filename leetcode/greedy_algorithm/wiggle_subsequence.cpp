/*
 * @Author: Chacha
 * @Date: 2022-04-16 23:18:10
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-17 23:05:41
 */

/**
 * 来源：https://leetcode-cn.com/problems/wiggle-subsequence/
 *
 * 376. 摆动序列
 * 如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。
 * 仅有一个元素或者含两个不等元素的序列也视作摆动序列。
 *
 * 1. 例如，[1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的。
 * 2. 相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，
 *    第二个序列是因为它的最后一个差值为零。
 *
 * 子序列可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。
 * 给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的最长子序列的长度。
 *
 * 示例 1:
 * 输入: [1, 7, 4, 9, 2, 5]
 * 输出: 6
 * 解释: 整个序列均为摆动序列。
 *
 * 示例 2:
 * 输入: [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
 * 输出: 7
 * 解释: 这个序列包含几个长度为 7 摆动序列，其中一个可为[1, 17, 10, 13, 10, 16, 8]
 *
 * 示例 3:
 * 输入: [1, 2, 3, 4, 5, 6, 7, 8, 9]
 * 输出: 2
 *
 */

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Solution
{
private:
    /* data */
public:
    int dp[1005][2];

    int wiggleMaxLength(vector<int> &nums);

    int wiggleMaxLength1(vector<int> &nums);
};

/**
 * 方法一：贪心
 * 局部最优：删除单调坡度上的节点（不包括单调坡度两端的节点），那么这个坡度就可以有两个局部峰值。
 * 整体最优：整个序列有最多的局部峰值，从而达到最长摆动序列。
 *
 * 例如序列[2,5]，它的峰值数量是2，如果靠统计差值来计算峰值个数就需要考虑数组最左面和最右面的特殊情况。
 * 所以可以针对序列[2,5]，可以假设为[2,2,5]，这样它就有坡度了即preDiff = 0，如图：
 *            5
 *           /
 * 2 ---- 2 /
 *   preDiff = 0; curDiff = 3;
 *
 * 针对以上情形，result初始为1（默认最右面有一个峰值），此时curDiff > 0 && preDiff <= 0，
 * 那么result++（计算了左面的峰值），最后得到的result就是2（峰值个数为2即摆动序列长度为2）
 *
 */
int Solution::wiggleMaxLength(vector<int> &nums)
{
    if (nums.size() <= 1)
    {
        return nums.size();
    }

    int curDiff = 0; // 当前一对差值
    int preDiff = 0; // 前一对差值
    int result = 1;  // 记录峰值个数，序列默认序列最右边有一个峰值

    for (int i = 0; i < nums.size() - 1; i++)
    {
        curDiff = nums[i + 1] - nums[i];

        // 如果遇到峰值
        if ((curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0))
        {
            result++;
            preDiff = curDiff;
        }
    }

    return result;
};

/**
 * 动态规划
 *
 * 很容易发现，对于我们当前考虑的这个数，要么是作为山峰（即nums[i] > nums[i-1]），要么是作为山谷（即nums[i] < nums[i - 1]）。
 * 1. 设dp状态dp[i][0]，表示考虑前i个数，第i个数作为山峰的摆动子序列的最长长度
 * 2. 设dp状态dp[i][2]，表示考虑前i个数，第i个数作为山谷的摆动子序列的最长长度
 *
 * 则转移方程为：
 * 1. dp[i][0] = max(dp[i][0], dp[j][1] + 1)，其中 0 < j < i 且 nums[j] < nums[i]，表示将nums[i]接到前面某个山谷后面，作为山峰。
 * 2. dp[i][1] = max(dp[i][1], dp[j][0] + 1)，其中 0 < j < i 且 nums[j] > nums[i]，表示将nums[i]接到前面某个山峰后面，作为山谷。
 *
 * 初始状态：
 * 由于一个数可以接到前面的某个数后面，也可以以自身为子序列的起点，所以初始状态为：dp[0][0] = dp[0][1] = 1。
 *
 */
int Solution::wiggleMaxLength1(vector<int> &nums)
{
    // void *memset(void *str, int c, size_t n) 复制字符 c（一个无符号字符）到参数 str 所指向的字符串的前 n 个字符。
    memset(dp, 0, sizeof dp);

    dp[0][0] = dp[0][1] = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        dp[i][0] = dp[i][1] = 1;

        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[i])
            {
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
        }

        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
        }
    }

    return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {1, 7, 4, 9, 2, 5};
    vector<int> nums1 = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};

    cout << "wiggleMaxLength [1, 7, 4, 9, 2, 5]：" << s.wiggleMaxLength(nums) << endl;
    cout << "wiggleMaxLength [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]：" << s.wiggleMaxLength(nums1) << endl;

    cout << "\n wiggleMaxLength1 [1, 7, 4, 9, 2, 5]：" << s.wiggleMaxLength1(nums) << endl;
    cout << "wiggleMaxLength1 [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]：" << s.wiggleMaxLength1(nums1) << endl;

    return 0;
}
