/*
 * @Author: Chacha
 * @Date: 2022-03-08 11:13:10
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-08 16:42:28
 */

/**
 * 来源：https://leetcode-cn.com/problems/integer-break/
 *
 * 动态规划 - 整数拆分
 * 给定一个正整数 n（n 不小于 2 且不大于 58），将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。返回你可以获得的最大乘积。
 *
 * 示例 1:
 * 输入: 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 *
 * 示例 2:
 * 输入: 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
 *
 */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
    int integerBreak(int n);
};

/**
 * 动态规划五部曲：
 * 1. 确定dp数组(dp table)以及下标的定义
 *    dp[i]: 分拆数字i，可以得到的最大乘积为dp[i]
 * 2. 确定递推公式
 *    dp[i]的最大乘积要怎么得到呢？
 *    0 不是正整数，1 是最小的正整数，0 和 1 都不能拆分。
 *    当 i >= 2 时，假设对正整数 i 拆分出的第一个正整数是 j(1 <= j < i), 则有以下两种方案：
 *    1. 将 i 拆分成 j 和 i - j的和，且 i - j不再拆分成多个正整数，此时的乘积是 j x (i - j);
 *    2. 将 i 拆分成 j 和 i - j的和，且 i - j继续拆分成多个正整数，此时的乘积是 j x dp[i - j];
 *
 *    当 j 固定时，有 dp[i] = max((i - j) * j, dp(i - j) * j)，由于 j 的取值范围是 1 到 i - 1,
 *    需要遍历所有的 j 得到 dp[i] 的最大值，因此可以得到最终的计算公式为：
 *    dp[i] = max(dp[i], max((i - j) * j, dp(i - j) * j))
 *
 * 3. dp的初始化
 *    严格从 dp[i] 的定义来看，dp[0] dp[1] 不应该初始化，也是没有意义的数值。拆分0和拆分1的最大乘积可以认为无解。
 *    所以这里，我们只初始化 dp[2] = 1。枚举j的时候，是从1开始的。i是从3开始，
 *    这样 dp[i - j] 就是 dp[2] 正好可以通过我们初始化的数值求出来。
 * 4. 确定遍历顺序
 *    确定遍历顺序，先来看看递归公式：dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
 *    dp[i] 是依靠 dp[i - j] 的状态，所以遍历 i 一定是从前向后遍历，先有 dp[i - j] 再有 dp[i]。
 * 5. 举例推倒 dp 数组
 *    举例当 n 为 10的时候，dp数组里的数值，如下：
 *    下标i：   2   3   4   5   6   7   8   9   10
 *    dp[1]：  1   2   3   6   9   12  18  27  36
 *
 * LeetCode官方题解：https://leetcode-cn.com/problems/integer-break/solution/zheng-shu-chai-fen-by-leetcode-solution/
 *
 */
int Solution::integerBreak(int n)
{
    vector<int> dp(n + 1);
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j < i - 1; j++)
        {
            dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
        }
    }

    return dp[n];
}

int main(int argc, char const *argv[])
{
    Solution s;

    cout << "n = 2, 整数拆分结果：" << s.integerBreak(2) << endl;
    cout << "n = 10, 整数拆分结果：" << s.integerBreak(10) << endl;

    return 0;
}
