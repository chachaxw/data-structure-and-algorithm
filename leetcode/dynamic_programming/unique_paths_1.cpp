/*
 * @Author: Chacha
 * @Date: 2022-03-05 13:40:09
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-08 19:23:08
 */

/**
 * 来源：https://leetcode-cn.com/problems/unique-paths-ii/
 *
 * 动态规划 - 不同路径II
 * 一个机器人位于一个 m x n (1 <= m, n <= 100) 网格的左上角 （起始点在下图中标记为 “Start” ）。
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？网格中的障碍物和空位置分别用 1 和 0 来表示。
 *
 * 示例 1：
 * 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * 输出：2
 *
 * ├─────────────────│
 * │  S  │  0  │  0  │
 * ├─────────────────│
 * │  0  │  1  │  0  │
 * ├─────────────────│
 * │  0  │  0  │  F  │
 * ├─────────────────│
 *
 * 解释：3 x 3网格的正中间有一个障碍物。从左上角到右下角一共有2条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid);
};

/**
 * 机器人从(0 , 0) 位置出发，到(m - 1, n - 1)终点。
 * 按照动态规划五部曲来分析：
 * 1. 确定dp数组(dp table)以及下标的含义
 *    dp[i][j]: 表示从(0, 0)出发，到(i, j) 有 dp[i][j] 条不同的路径
 * 2. 确定递推公式
 *    可以推导出公式：dp[i][j] = dp[i - 1][j] + dp[i][j - 1]。因为有了障碍，所以当(i, j)没有障碍的时候，再推导dp[i][j]。
 *    所以代码为：
 *    if (obstacleGrid[i][j] == 0) dp[i][j] = dp[i - 1][j] + dp[j][i - 1]
 * 3. dp数组初始化
 *    首先dp[i][0]一定都是1，因为从(0, 0)的位置到(i, 0)的路径只有一条，那么dp[0][j]也同理。
 *    但如果(i, 0)这条边又了障碍之后，障碍之后都是走不到的位置，所以障碍之后的dp[i][0]应该还是初始值0。
 *    ├─────────────────────────────────────────│
 *    │  1  │  1  │  1  │ 障碍 │  0  │  0  │  0  │
 *    ├─────────────────────────────────────────│
 *    所以初始化代码为：
 *    for(int i = 0, i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
 *    for(int j = 0, j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
 * 4. 确定遍历顺序
 *    根据递归公式 dp[i][j] = dp[i - 1][j] + dp[i][j - 1] 可以看出，dp[i][j] 都是从其上方或者左方推导出来，
 *    所以从左到右一层一层遍历就可以了。这样就可以保证推导dp[i][j]的时候，dp[i - 1][j] 和 dp[i][j - 1]一定是有数值的。
 *    代码如下：
 *    for (int i = 1; i < m; i++) {
 *        for (int j = 1; j < n; j++) {
 *            if (obstacleGrid[i][j] == 1) continue;
 *            dp[i][j] = dp[i - 1][j] + dp[i][j-1]
 *        }
 *    }
 *
 * 5. 举例推导dp数组
 *    obstacleGrid = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
 * ├─────────────────│
 * │  S  │  1  │  1  │
 * ├─────────────────│
 * │  1  │  0  │  1  │
 * ├─────────────────│
 * │  1  │  1  │  F  │
 * ├─────────────────│
 *
 * 时间复杂度: O(m × n)
 * 空间复杂度: O(m x n)
 *
 */
int Solution::uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++)
        dp[i][0] = 1;

    for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++)
        dp[0][j] = 1;

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
                continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<int>> obstacleGrid(3, vector<int>(3, 0));
    vector<vector<int>> obstacleGrid1(2, vector<int>(2, 0));

    obstacleGrid[1][1] = 1;
    obstacleGrid1[0][1] = 1;

    cout << "Result is: " << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    cout << "Result is: " << s.uniquePathsWithObstacles(obstacleGrid1) << endl;

    return 0;
}
