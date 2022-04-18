/*
 * @Author: Chacha
 * @Date: 2022-04-18 14:53:00
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-18 15:19:30
 */

/**
 * 来源：https://leetcode-cn.com/problems/maximum-subarray/
 *
 * 53. 最大子数组和
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 子数组 是数组中的一个连续部分。
 *
 * 示例 1：
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 *
 * 示例 2：
 * 输入：nums = [1]
 * 输出：1
 *
 * 示例 3：
 * 输入：nums = [5,4,-1,7,8]
 * 输出：23
 *
 * 提示：
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10
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
    int maxSubArray(vector<int> &nums);
};

/**
 * 贪心解法
 *
 * 贪心贪的是哪里呢？如果 -2 1 在一起，计算起点的时候，一定是从 1 开始计算，因为负数只会拉低总和，这就是贪心贪的地方。
 *
 * 局部最优解：当前"连续和"为负数的时候立刻放弃，从下一个元素重新计算“连续和”，因为负数加上一个元素“连续和”只会越来越小。
 * 全局最优：选取最大“连续和”
 *
 * 从代码角度上来讲：遍历 nums，从头开始用 count 累积，如果 count 一旦加上 nums[i] 变为附属，那么就应该从 nums[i + 1] 开始
 * 从 0 累积 count 了，因为已经变为负数的 count，只会拖累总和。
 *
 * 这相当于是暴力解法中的不断调整最大子序和区间的起始位置。如何才能得到最大“连续和”呢？
 * 区间的终止位置，其实就是如果count取到最大值了，及时记录下来了。例如如下代码：
 * if (count > result) result = count;
 * 这样相当于是用result记录最大子序和区间和（变相的算是调整了终止位置）。
 *
 */
int Solution::maxSubArray(vector<int> &nums)
{
    int result = INT32_MIN;
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        count += nums[i];

        if (count > result)
        {
            // 取区间累计的最大值（相当于不断确定最大子序终止位置）
            result = count;
        }

        if (count <= 0)
        {
            // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
            count = 0;
        }
    }

    return result;
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums1 = {5, 4, -1, 7, 8};

    std::cout << "[-2, 1, -3, 4, -1, 2, 1, -5, 4]最大子数组和: " << s.maxSubArray(nums) << std::endl;
    std::cout << "[5, 4, -1, 7, 8]最大子数组和: " << s.maxSubArray(nums1) << std::endl;

    return 0;
}
