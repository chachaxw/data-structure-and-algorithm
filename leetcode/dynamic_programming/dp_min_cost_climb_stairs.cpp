/*
 * @Author: Chacha
 * @Date: 2022-03-02 16:09:51
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-03 10:46:46
 */

/**
 * 来源：https://leetcode-cn.com/problems/min-cost-climbing-stairs/
 *
 * 动态规划 - 使用最小花费爬楼梯
 * 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
 * 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。请你计算并返回达到楼梯顶部的最低花费。
 *
 * 2 <= cost.length <= 1000
 * 0 <= cost[i] <= 999
 *
 * 示例1:
 * 输入：cost = [10,15,20]
 * 输出：15
 * 解释：你将从下标为 1 的台阶开始。- 支付 15，向上爬两个台阶，到达楼梯顶部，总花费为 15 。
 *
 * 示例2:
 * 输入：cost = [1,100,1,1,1,100,1,1,100,1]
 * 输出：6
 * 解释：你将从下标为 0 的台阶开始。
 * - 支付 1，向上爬两个台阶，到达下标为 2 的台阶。
 * - 支付 1，向上爬两个台阶，到达下标为 4 的台阶。
 * - 支付 1，向上爬两个台阶，到达下标为 6 的台阶。
 * - 支付 1，向上爬一个台阶，到达下标为 7 的台阶。
 * - 支付 1，向上爬两个台阶，到达下标为 9 的台阶。
 * - 支付 1，向上爬一个台阶，到达楼梯顶部。
 * 总花费为 6。
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> cost);

    int minCostClimbingStairs1(vector<int> cost);
};

/**
 * 题解：
 * 1. 确定dp数组以及下标的含义
 *    dp[i]的定义：到达第i个台阶所花费的最少体力为dp[i]。
 * 2. 确定递推公式
 *    可以有两个途径得到dp[i]，一个是dp[i-1]，一个是dp[i-2]，那么究竟是 dp[i-1] 还是 dp[i-2]?
 *    这里肯定是选择花费最小的那一个，所以 dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]。
 *    加 cost[i] 是因为到达 第 i - 1 或者 第 i - 2个台阶时，需要再花费cost[i]才能到达楼顶。
 * 3. dp数组如何初始化
 *    从递推公式可以看出，dp[i] 由 dp[i-1] 和 dp[i-2] 推导出，所以只需要初始化dp[0] 和 dp[1]即可，
 *    其他的最终都由 dp[0] 和 dp[1]推导出。所以初始化为: dp[0] = cost[0]; dp[1] = cost[1];
 * 4. 确定遍历顺序
 *    从递推公式 dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]; 中可以看出，遍历顺序一定是从前向后遍历的。
 * 5. 举例推导dp数组
 *    拿示例2：cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]，来模拟一下dp数组的状态变化，如下：
 *    下标:     0     1     2     3     4     5     6     7     8     9
 *    dp[i]:   1    100    2     3     3    103    4     5    104    6
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 *
 */
int Solution::minCostClimbingStairs(vector<int> cost)
{
    vector<int> dp(cost.size());

    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < cost.size(); i++)
    {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }

    // 最后一步可以理解为不用花费，所以取倒数第一步，第二步的最少值
    return min(dp[cost.size() - 1], dp[cost.size() - 2]);
};

/**
 * 用滚动数组的方式优化空间复杂度
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
int Solution::minCostClimbingStairs1(vector<int> cost)
{
    int dp0 = cost[0];
    int dp1 = cost[1];

    for (int i = 2; i < cost.size(); i++)
    {
        int dpi = min(dp0, dp1) + cost[i];
        dp0 = dp1;
        dp1 = dpi;
    }

    return min(dp0, dp1);
};

int main(int argc, char const *argv[])
{
    Solution s;

    int arr[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int arr1[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1, 1, 100, 1, 100};
    vector<int> cost(arr, arr + sizeof(arr) / sizeof(int));
    vector<int> cost1(arr1, arr1 + sizeof(arr1) / sizeof(int));

    cout << "minCostClimbingStairs cost = " << s.minCostClimbingStairs(cost) << endl;
    cout << "minCostClimbingStairs1 cost1 = " << s.minCostClimbingStairs1(cost1) << endl;

    return 0;
}
