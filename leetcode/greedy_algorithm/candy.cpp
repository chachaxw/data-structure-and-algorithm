/*
 * @Author: Chacha
 * @Date: 2022-06-12 15:53:38
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-06-12 18:54:40
 */

/**
 * 来源：https://leetcode.cn/problems/candy/
 *
 * 135. 分发糖果
 *
 * n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。你需要按照以下要求，给这些孩子分发糖果：
 * 1. 每个孩子至少分配到 1 个糖果。
 * 2. 相邻两个孩子评分更高的孩子会获得更多的糖果。
 *
 * 请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
 *
 * 示例 1：
 * 输入：ratings = [1,0,2]
 * 输出：5
 * 解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
 *
 * 示例 2：
 * 输入：ratings = [1,2,2]
 * 输出：4
 * 解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
        第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。
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
    int candy(vector<int> &ratings);
};

/**
 * 方法：贪心
 *
 * 思路：
 * 这道题目一定是要确定一边之后，再确定另一边，例如比较每一个孩子的左边，然后再比较右边，如果两边一起考虑一定会顾此失彼。
 *
 * 1. 先确定右边评分大于左边的情况（也就是从前向后遍历）
 * 此时局部最优：只要右边评分比左边大，右边的孩子就多一个糖果，全局最优：相邻的孩子中，评分高的右孩子获得比左边孩子更多的糖果
 * 局部最优可以推出全局最优。如果ratings[i] > ratings[i - 1] 那么[i]的糖 一定要比[i - 1]的糖多一个，
 * 所以贪心：candyVec[i] = candyVec[i - 1] + 1
 *
 * 代码如下：
 * // 从前向后
 * for (int i = 1; i < ratings.size(); i++) {
 *   if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
 * }
 *
 * 如图：
 * 下标：    0     1     2     3     4     5     6
 * 评分：    1     2     2     5     4     3     2
 *
 * 从左向右比较左孩子糖果分发candyVec：
 * 糖果：    1     2     1     2     1     1     1
 *
 * 2. 再确定左孩子大于右孩子的情况（从后向前遍历）
 * 为什么不能从前向后遍历呢？因为如果从前向后遍历，根据 ratings[i + 1] 来确定 ratings[i] 对应的糖果，
 * 那么每次都不能利用上前一次的比较结果了。所以确定左孩子大于右孩子的情况一定要从后向前遍历！
 *
 * 如果 ratings[i] > ratings[i + 1]，此时candyVec[i]（第i个小孩的糖果数量）就有两个选择了，
 * 一个是candyVec[i + 1] + 1（从右边这个加1得到的糖果数量），
 * 一个是candyVec[i]（之前比较右孩子大于左孩子得到的糖果数量）。
 *
 * 局部最优：取candyVec[i + 1] + 1 和 candyVec[i] 最大的糖果数量，保证第i个小孩的糖果数量即大于左边的也大于右边的。
 * 全局最优：相邻的孩子中，评分高的孩子获得更多的糖果。局部最优可以推出全局最优。
 * 所以就取candyVec[i + 1] + 1 和 candyVec[i] 最大的糖果数量，candyVec[i] 只有取最大的
 * 才能既保持对左边candyVec[i - 1]的糖果多，也比右边candyVec[i + 1]的糖果多。
 *
 * 如图：
 * 下标：    0     1     2     3     4     5     6
 * 评分：    1     2     2     5     4     3     2
 *
 * 从左向右比较左孩子糖果分发candyVec：
 * 糖果：    1     2     1     2     1     1     1
 *
 * 从右向左比较右孩子 i 为 5的时候：
 * 糖果：    -     -     -     -     -     ?     1
 *
 * 从右向左比较右孩子糖果分发candyVec：
 * 糖果：    1     2     1     4     3     2     1
 *
 * i 为5时，ratings[i] > ratings[i+1]，那么 candyVec[i] = max(candyVec[i], candyVec[i+1] + 1)
 *
 * 代码如下：
 * // 从后向前
 * for (int i = ratings.size() - 2; i >= 0; i--) {
 *   if (ratings[i] > ratings[i+1]) {
 *     candyVec[i] = max(candyVec[i], candyVec[i+1] + 1);
 *   }
 * }
 *
 * 时间复杂度：O(n)，其中 n 是孩子的数量。我们需要遍历两次数组以分别计算满足左规则或右规则的最少糖果数量。
 * 空间复杂度：O(n)，其中 n 是孩子的数量。我们需要保存所有的左规则对应的糖果数量。
 *
 */
int Solution::candy(vector<int> &ratings)
{
    // 初始化 candyVec 数据，默认都为 1
    vector<int> candyVec(ratings.size(), 1);

    // 从前向后
    for (int i = 1; i < ratings.size(); i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            candyVec[i] = candyVec[i - 1] + 1;
        }
    }

    // 从后向前
    for (int i = ratings.size() - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
        }
    }

    // 统计结果
    int result = 0;

    for (int i = 0; i < candyVec.size(); i++)
    {
        result += candyVec[i];
    }

    return result;
}

int main(int argc, char const *argv[])
{
    // --std=c++11
    vector<int> ratings = {1, 0, 2};
    vector<int> ratings1 = {1, 2, 2};
    vector<int> ratings2 = {1, 2, 2, 5, 4, 3, 2};
    Solution s;

    cout << "ratings = [1, 0, 2], output: " << s.candy(ratings) << endl;              // 5
    cout << "ratings = [1, 2, 2], output: " << s.candy(ratings1) << endl;             // 4
    cout << "ratings = [1, 2, 2, 5, 4, 3, 2], output: " << s.candy(ratings2) << endl; // 14

    /* code */
    return 0;
}
