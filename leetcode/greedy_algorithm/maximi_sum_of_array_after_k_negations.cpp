/*
 * @Author: Chacha
 * @Date: 2022-05-17 22:14:56
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-05-17 22:42:44
 */

/**
 * 来源：https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/
 *
 * 1005. K 次取反后最大化的数组和
 *
 * 给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：
 * 选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
 * 重复这个过程恰好 k 次。可以多次选择同一个下标 i 。
 * 以这种方式修改数组后，返回数组 可能的最大和 。
 *
 * 示例 1：
 * 输入：nums = [4,2,3], k = 1
 * 输出：5
 * 解释：选择下标 1 ，nums 变为 [4,-2,3] 。
 *
 * 示例 2：
 * 输入：nums = [3,-1,0,2], k = 3
 * 输出：6
 * 解释：选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。
 *
 * 示例 3：
 * 输入：nums = [2,-3,-1,5,-4], k = 2
 * 输出：13
 * 解释：选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4] 。
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{

    static bool compare(int a, int b);

private:
    /* data */
public:
    int largestSumAfterKNegations(vector<int> &nums, int k);
};

bool Solution::compare(int a, int b)
{
    return abs(a) > abs(b);
}

/**
 * 方法：贪心的思路
 *
 * 局部最优：让绝对值大的负数变为正数，当前数值达到最大，整体最优：整个数组和达到最大。
 * 那么如果将负数都转变为正数了，K依然大于0，此时的问题是一个有序正整数序列，如何转变K次正负，让数组和达到最大。
 * 那么又是一个贪心：局部最优：只找数值最小的正整数进行反转，当前数值可以达到最大，
 * 例如正整数数组{5, 3, 1}，反转1 得到-1 比 反转5得到的-5 大多了，全局最优：整个 数组和 达到最大。
 *
 * 解题步骤：
 * 1. 将数组按照绝对值大小从大到小排序，注意要按照绝对值的大小。
 * 2. 从前向后遍历，遇到负数将其变为正数，同时K--
 * 3. 如果K还大于0，那么反复转变数值最小的元素，将K用完
 * 4. 求和
 *
 */
int Solution::largestSumAfterKNegations(vector<int> &nums, int k)
{
    // 按绝对值大小从大到小排序
    sort(nums.begin(), nums.end(), compare);

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0 && k > 0)
        {
            nums[i] *= -1;
            k--;
        }
    }

    if (k % 2 == 1)
    {
        nums[nums.size() - 1] *= -1;
    }

    int result = 0;
    for (int n : nums)
        result += n; // 第四步

    return result;
}

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {4, 2, 3};
    vector<int> nums1 = {3, -1, 0, 2};
    vector<int> nums2 = {2, -3, -1, 5, -4};

    cout << "nums = [4, 2, 3], k = 1, 最大和: " << s.largestSumAfterKNegations(nums, 1) << endl;
    cout << "nums = [3,-1,0,2], k = 3, 最大和: " << s.largestSumAfterKNegations(nums1, 3) << endl;
    cout << "nums = [2,-3,-1,5,-4], k = 2, 最大和: " << s.largestSumAfterKNegations(nums2, 2) << endl;

    return 0;
}
