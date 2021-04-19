/**
 * @Author: Chacha
 * @Date: 2018-12-28 18:05:11
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-04-19 18:10:11
 */

/**
 * 给你一个整数数组 nums，请编写一个能够返回数组 “中心下标” 的方法。数组 中心下标 是数组的一个下标，
 * 其左侧所有元素相加的和等于右侧所有元素相加的和。如果数组不存在中心下标，返回 -1 。
 * 如果数组有多个中心下标，应该返回最靠近左边的那一个。
 *
 * 注意：中心下标可能出现在数组的两端。
 *
 * 示例:
 *  输入: nums = [1, 7, 3, 6, 5, 6]
 *  输出: 3
 *
 * 解释:
 *  左侧数之和 (1 + 7 + 3 = 11)，右侧数之和 (5 + 6 = 11) ，二者相等。
 *
 * Note:
 *  1. nums 的长度范围为 [0, 10000]
 *  2. 任何一个 nums[i] 将会是一个范围在 [-1000, 1000]的整数
 *
 * 来源: https://leetcode.com/problems/find-pivot-index/
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * 题解：
 * 计算出全部数组的和，当遍历到第i个元素时，设其左侧元素之和为sum，则其右侧元素之和为 total - numsi - sum。
 * 左右侧元素相等即为 sum = total - numsi - sum，即 2 x sum + numsi = total。
 *
 * 当中心索引左侧或右侧没有元素时，即为零个项相加，这在数学上称作「空和」（empty sum）。在程序设计中我们约定「空和是零」。
 *
 */
int pivotIndex(vector<int> &nums)
{
    int total = 0;

    for (int num : nums)
        total += num;

    int sum = 0;
    for (int i = 0; i < nums.size(); sum += nums[i++])
    {
        if (sum * 2 == total - nums[i])
            return i;
    }

    return -1;
}

int main()
{
    int arr[] = {1, 7, 3, 6, 5, 6};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    int result = pivotIndex(nums);

    cout << "Result is " << result << endl;
}
