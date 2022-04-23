/*
 * @Author: Chacha
 * @Date: 2022-04-23 23:33:43
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-23 23:59:19
 */

/**
 * 来源：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 *
 * 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
 * 在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
 * 返回 你能获得的 最大 利润 。
 *
 * 示例 1：
 * 输入：prices = [7,1,5,3,6,4]
 * 输出：7
 * 解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
 * 随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。
 * 总利润为 4 + 3 = 7 。
 *
 * 示例 2：
 * 输入：prices = [1,2,3,4,5]
 * 输出：4
 * 解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
 * 总利润为 4 。
 *
 * 示例 3：
 * 输入：prices = [7,6,4,3,1]
 * 输出：0
 * 解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0 。
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
    int maxProfit(vector<int> &prices);
};

/**
 * 方法：贪心算法
 *
 * 思路：
 * 本题首先要清楚两点：
 *  1.只有一只股票
 *  2.当前只有买股票或者买股票的操作
 * 想获得利润至少要两天为一个交易单元。
 *
 * 如果想到其实最终利润是可以分解的，那么本题就很容易了！如何分解呢？
 * 假如第0天买入，第3天卖出，那么利润为：prices[3] - prices[0]。
 * 相当于(prices[3] - prices[2]) + (prices[2] - prices[1]) + (prices[1] - prices[0])。
 * 此时就是把利润分解为每天为单位的维度，而不是从0天到第3天整体去考虑。
 * 那么根据prices可以得到每天的利润序列：(prices[i] - prices[i - 1]).....(prices[1] - prices[0])。
 *
 * 时间复杂度：$O(n)
 * 空间复杂度：$O(1)
 *
 */
int Solution::maxProfit(vector<int> &prices)
{
    int result = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        result += max(prices[i] - prices[i - 1], 0);
    }
    return result;
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "prices = [7,1,5,3,6,4], 最大利润为" << s.maxProfit(prices) << endl;

    return 0;
}
