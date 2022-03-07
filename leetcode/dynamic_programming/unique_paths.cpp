/*
 * @Author: Chacha
 * @Date: 2022-03-05 13:40:09
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-05 20:32:53
 */

/**
 * 来源：https://leetcode-cn.com/problems/unique-paths/
 *
 * 动态规划 - 不同路径
 * 一个机器人位于一个 m x n (1 <= m, n <= 100) 网格的左上角 （起始点在下图中标记为 “Start” ）。
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 * 问总共有多少条不同的路径？
 *
 * 示例 1：
 * 输入：m = 3, n = 7
 * 输出：28
 *
 * ├───────────────────────────│
 * │ S │   │   │   │   │   │   │
 * ├───────────────────────────│
 * │   │   │   │   │   │   │   │
 * ├───────────────────────────│
 * │   │   │   │   │   │   │ F │
 * ├───────────────────────────│
 *
 *
 * 示例 2：
 * 输入：m = 2, n = 3
 * 输出：3
 * 解释： 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向右 -> 向下
 * 2. 向右 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向右
 *
 * 示例 3：
 * 输入：m = 7, n = 3
 * 输出：28
 *
 * 示例 4：
 * 输入：m = 3, n = 3
 * 输出：6
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n);

    int uniquePaths1(int m, int n);
};

/**
 * 机器人从(0 , 0) 位置出发，到(m - 1, n - 1)终点。
 * 按照动规五部曲来分析：
 * 1. 确定dp数组(dp table)以及下标的含义
 *    dp[i][j]: 表示从(0, 0)出发，到(i, j) 有 dp[i][j] 条不同的路径
 * 2. 确定递推公式
 *    要求dp[i][j]的值，可以从两个方向来推导，即 dp[i-1][j] 和 dp[i][j-1]
 *    dp[i - 1][j] 表示从(0, 0)的位置到(i - 1, j)有几条路径, dp[i][j-1]同理
 *    因此可以推导出公式：dp[i][j] = dp[i - 1][j] + dp[i][j - 1]，因为dp[i][j]只有这两个方向过来。
 * 3. dp数组初始化
 *    首先dp[i][0]一定都是1，因为从(0, 0)的位置到(i, 0)的路径只有一条，那么dp[0][j]也同理。
 *    所以初始化代码为：
 *    for(int i = 0, i < m; i++) dp[i][0] = 1;
 *    for(int j = 0, j < n; j++) dp[0][j] = 1;
 * 4. 确定遍历顺序
 *    根据递归公式 dp[i][j] = dp[i - 1][j] + dp[i][j - 1] 可以看出，dp[i][j] 都是从其上方或者左方推导出来，
 *    所以从左到右一层一层遍历就可以了。这样就可以保证推导dp[i][j]的时候，dp[i - 1][j] 和 dp[i][j - 1]一定是有数值的。
 * 5. 举例推导dp数组
 *    m = 3, n = 7
 * ├───────────────────────────│
 * │ 1 │ 1 │ 1 │ 1 │ 1 │ 1 │ 1 │
 * ├───────────────────────────│
 * │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │
 * ├───────────────────────────│
 * │ 1 │ 3 │ 6 │10 │15 │21 │28 │
 * ├───────────────────────────│
 *
 * 时间复杂度: O(m × n)
 * 空间复杂度: O(m x n)
 *
 */
int Solution::uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
        dp[i][0] = 1;
    for (int j = 0; j < n; j++)
        dp[0][j] = 1;

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
};

/**
 * 可以用一位数组进行优化，类似滚动数组的方式
 * 时间复杂度: O(m × n)
 * 空间复杂度: O(n)
 */
int Solution::uniquePaths1(int m, int n)
{
    vector<int> dp(n);

    for (int i = 0; i < m; i++)
        dp[i] = 1;

    for (int j = 1; j < m; j++)
    {
        for (int i = 1; i < n; i++)
        {
            dp[i] += dp[i - 1];
        }
    }

    return dp[n - 1];
};

int main(int argc, char const *argv[])
{
    Solution s;
    int m = 3, n = 7;
    int m1 = 5, n1 = 9;

    cout << "Result is: " << s.uniquePaths(m, n) << endl;
    cout << "Result is: " << s.uniquePaths1(m1, n1) << endl;

    return 0;
}
