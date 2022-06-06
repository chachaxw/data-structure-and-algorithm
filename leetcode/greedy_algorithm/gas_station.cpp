/*
 * @Author: Chacha
 * @Date: 2022-06-06 22:34:23
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-06-06 23:28:32
 */

/**
 * 来源：https://leetcode-cn.com/problems/gas-station/
 *
 * 134. 加油站
 *
 * 在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。你有一辆油箱容量无限的的汽车，
 * 从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
 * 如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。
 *
 * 说明:
 * 1. 如果题目有解，该答案即为唯一答案。
 * 2. 输入数组均为非空数组，且长度相同。
 * 3. 输入数组中的元素均为非负数。
 *
 * 示例 1:
 * 输入:
 * gas = [1,2,3,4,5]
 * cost = [3,4,5,1,2]
 *
 * 输出: 3
 *
 * 解释:
 * 从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油；
 * 开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油；
 * 开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油；
 * 开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油；
 * 开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油；
 * 开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
 * 因此，3 可为起始索引。
 *
 * 示例 2:
 * 输入:
 * gas = [2,3,4]
 * cost = [3,4,3]
 *
 * 输出: -1
 *
 * 解释:
 * 你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
 * 我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油；
 * 开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油；
 * 开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油；
 * 你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
 * 因此，无论怎样，你都不可能绕环路行驶一周。
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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost);
};

/**
 * 方法：贪心算法
 *
 * 直接从全局进行贪心选择，情况如下：
 * 1. 情况一：如果 gas 的总和小于 cost 总和，那么无论从哪里出发，一定是跑不了一圈的
 * 2. 情况二：rest[i] = gas[i] - cost[i]为一天剩下的油，i 从 0 开始计算累加到最后一站，
 *    如果累加没有出现负数，说明从 0 出发，油就没有断过，那么0就是起点。
 * 3. 如果累加的最小值是负数，汽车就要从非0节点出发，从后向前，看哪个节点能这个负数填平，能把这个负数填平的节点就是出发节点。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 *
 */
int Solution::canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int curSum = 0;
    int min = INT_MAX; // 从起点出发，油箱里的油量最小值

    for (int i = 0; i < gas.size(); i++)
    {
        int rest = gas[i] - cost[i];

        curSum += rest;

        if (curSum < min)
        {
            min = curSum;
        }
    }

    if (curSum < 0)
    {
        // 对应上述情况一
        return -1;
    }

    if (min >= 0)
    {
        // 对应上述情况二
        return 0;
    }

    // 对应上述情况三
    for (int i = gas.size() - 1; i >= 0; i--)
    {
        int rest = gas[i] - cost[i];

        min += rest;

        if (min >= 0)
        {
            return i;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    vector<int> gas1 = {2, 3, 4};
    vector<int> cost1 = {3, 4, 3};

    cout << "gas: [1, 2, 3, 4, 5], cost: [3, 4, 5, 1, 2], result is: " << s.canCompleteCircuit(gas, cost) << endl;
    cout << "\ngas: [2, 3, 4], cost: [3, 4, 3], result is: " << s.canCompleteCircuit(gas1, cost1) << endl;

    return 0;
}
