/*
 * @Author: Chacha
 * @Date: 2022-03-01 10:21:49
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-01 14:07:24
 */

/**
 * 来源：https://leetcode-cn.com/problems/fibonacci-number/
 *
 * 动态规划 - 斐波那契数
 * 斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
 * F(0) = 0, F(1) = 1
 * F(n) = F(n-1) + F(n-2), 其中 n > 1 (1 < n <= 30)
 *
 * 示例 1：
 * 输入：n = 2
 * 输出：1
 * 解释：F(2) = F(1) + F(0) = 1 + 0 = 1
 *
 * 示例 2：
 * 输入：n = 3
 * 输出：2
 * 解释：F(3) = F(2) + F(1) = 1 + 1 = 2
 *
 * 示例 3：
 * 输入：n = 4
 * 输出：3
 * 解释：F(4) = F(3) + F(2) = 2 + 1 = 3
 *
 */

#include <iostream>

using namespace std;

class Solution
{
private:
    /* data */
public:
    int fib(int n);

    int fib1(int n);
};

/**
 * 解法1: 直接利用公式递归
 *
 * 时间复杂度: O(2^n)
 * 空间复杂度: O(n)
 *
 */
int Solution::fib(int n)
{
    return n < 2 ? n : fib(n - 1) + fib(n - 2);
}

/**
 * 解法2: 动态规划
 *
 * 动规五部曲：
 * 这里我们要用一个一维dp数组来保存递归的结果
 * 1. 确定dp数组以及下标的含义
 *    dp[i]的定义为：第i个数的斐波那契数值是dp[i]
 * 2. 确定递推公式
 *    斐波那契数列的公式: dp[i] = dp[i-1] + dp[i-2];
 * 3. dp数组初始化
 *    dp[0] = 0; dp[1] = 1;
 * 4. 确定遍历顺序，从递归公式 dp[i] = dp[i - 1] + dp[i - 2]; 中可以看出，
 *    dp[i]是依赖 dp[i - 1] 和 dp[i - 2]，那么遍历的顺序一定是从前到后遍历的
 * 5. 举例推导dp数组
 *    按照这个递推公式dp[i] = dp[i - 1] + dp[i - 2]，我们来推导一下，当N为10的时候，dp数组应该是如下的数列：
 *    0 1 1 2 3 5 8 13 21 34 55
 *
 *
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 *
 */

int Solution::fib1(int n)
{
    if (n < 2)
        return n;

    int dp[2];

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int sum = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = sum;
    }
    return dp[1];
}

int main(int argc, char const *argv[])
{
    Solution s;

    cout << "F(4) = " << s.fib(4) << endl;
    cout << "F(5) = " << s.fib(5) << endl;
    cout << "F(6) = " << s.fib(6) << endl;

    cout << "\nF(4) = " << s.fib1(4) << endl;
    cout << "F(5) = " << s.fib1(5) << endl;
    cout << "F(6) = " << s.fib1(6) << endl;
    return 0;
}
