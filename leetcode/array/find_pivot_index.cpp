/**
 * @Author: Chacha
 * @Date: 2018-12-28 18:05:11
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-03-26 18:11:00
 */

/***********************************************************************************
 * Given an array of integers nums, write a method that returns the "pivot" index of this array.
 * We define the pivot index as the index where the sum of the numbers to the left of the index
 * is equal to the sum of the numbers to the right of the index. If no such index exists,
 * we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.
 *
 * Example 1:
 *  Input:
 *  nums = [1, 7, 3, 6, 5, 6]
 *  Output: 3
 *  Explanation:
 *  The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to
 * the sum of numbers to the right of index 3. Also, 3 is the first index where this occurs.
 *
 * Note:
 *  1. The length of nums will be in the range [0, 10000].
 *  2. Each element nums[i] will be an integer in the range [-1000, 1000].
 *
 * Source: https://leetcode.com/problems/find-pivot-index/
************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

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
