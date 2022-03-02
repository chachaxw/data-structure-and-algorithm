/*
 * @Author: Chacha
 * @Date: 2022-03-01 17:19:41
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-02 16:07:52
 */

/**
 * 来源：https://leetcode-cn.com/problems/climbing-stairs/
 *
 * 动态规划 - 爬楼梯
 *
 * 假设你正在爬楼梯。需要 n (1 <= n <= 45) 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 *
 * 示例 1：
 * 输入：n = 2
 * 输出：2
 * 解释：有两种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶
 * 2. 2 阶
 *
 * 示例 2：
 * 输入：n = 3
 * 输出：3
 * 解释：有三种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶 + 1 阶
 * 2. 1 阶 + 2 阶
 * 3. 2 阶 + 1 阶
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
    int climbStairs(int n);

    int climbStairs1(int n);

    int climbStairs2(int n);
};

/**
 * 题解：
 * 爬到第一层楼梯有一种方法，爬到二层楼梯有两种方法。那么第一层楼梯再跨两步就到第三层，第二层楼梯再跨一步就到第三层。
 * 所以到第三层楼梯的状态可以由第二层楼梯和到第一层楼梯状态推导出来。
 *
 * 动态规划五部曲：
 * 定义一个一维数组来记录不同楼层的状态
 * 1. 确定dp数组以及下标的含义
 *    dp[i]: 爬到第i层楼，有dp[i]种方法
 * 2. 确定递推公式
 *    从dp[i]的定义可以看出，dp[i]可以有两个方向推出来。首先是dp[i-1], 上 i-1 层楼梯，有d[i-1]种方法，那么再一步跳一个台阶就是dp[i]。
 *    还有就是dp[i-2]，上 i-2 层楼梯，有dp[i-2]种方法，那么再一步跳两个台阶就是dp[i]。所以 dp[i] = dp[i-1] + dp[i-2]。
 * 3. dp数组初始化
 *    dp[i]的定义：爬到第i层楼梯，有dp[i]种方法。
 *    因为 n >= 1，所以不考虑dp[0]的始化，只初始化dp[1] = 1，dp[2] = 2，然后从i = 3开始递推，这样才符合dp[i]的定义。
 * 4. 确定遍历顺序
 *    从递推公式dp[i] = dp[i - 1] + dp[i - 2];中可以看出，遍历顺序一定是从前向后遍历的
 * 5. 推导dp数组
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 *
 */
int Solution::climbStairs(int n)
{
    if (n < 2)
        return n;

    vector<int> dp(n + 1);

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
};

/**
 * 用滚动数组的方式优化空间复杂度
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 *
 */
int Solution::climbStairs1(int n)
{
    if (n < 2)
        return n;

    int dp[3];

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        int sum = dp[1] + dp[2];
        dp[1] = dp[2];
        dp[2] = sum;
    }

    return dp[2];
};

/**
 * 假如讲一步1个台阶或2个台阶改为，一步1个台阶，2个台阶，3个台阶... 直到m个台阶。问有多少种不同的方法可以爬到楼顶？
 *
 */
int Solution::climbStairs2(int n)
{
    return 0;
};

int main(int argc, char const *argv[])
{
    Solution s;

    cout << "dp[2] = " << s.climbStairs(2) << endl;
    cout << "dp[3] = " << s.climbStairs(3) << endl;
    cout << "dp[4] = " << s.climbStairs(4) << endl;
    cout << "dp[5] = " << s.climbStairs(5) << endl;
    cout << "dp[6] = " << s.climbStairs(6) << endl;
    cout << "dp[7] = " << s.climbStairs(7) << endl;

    return 0;
}
