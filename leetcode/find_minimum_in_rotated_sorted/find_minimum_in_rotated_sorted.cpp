/*
 * @Author: Chacha
 * @Date: 2018-12-01 09:01:35
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-03-26 18:00:24
 */

#include <iostream>
#include <vector>

using namespace std;

/***********************************************************************************
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]). Find the minimum element.
 * You may assume no duplicate exists in the array.
 *
 * Example 1:
 *  Input: [3,4,5,1,2]
 *  Output: 1
 *
 * Example 2:
 *  Input: [4,5,6,7,0,1,2]
 *  Output: 0
 * Source: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
************************************************************************************/
int findMin1(vector<int> &nums)
{
    if (nums.empty())
    {
        return -1;
    }

    int start = 0, mid, end = nums.size() - 1;

    while (start + 1 < end)
    {
        mid = start + (end - start) / 2;

        if (nums[mid] < nums[end])
        {
            end = mid;
        }
        else
        {
            start = mid;
        }
    }

    if (nums[start] < nums[end])
    {
        return nums[start];
    }
    else
    {
        return nums[end];
    }
}

/***********************************************************************************
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * Find the minimum element. The array may contain duplicates.
 *
 * Example 1:
 *  Input: [1,3,5]
 *  Output: 1
 *
 * Example 2:
 *  Input: [2,2,2,0,1]
 *  Output: 0
 * Source: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
************************************************************************************/
int findMin2(vector<int> &nums)
{
    if (nums.empty())
    {
        return -1;
    }

    int start = 0, end = nums.size() - 1, mid;

    while (start + 1 < end)
    {
        mid = start + (end - start) / 2;

        if (nums[mid] < nums[end])
        {
            end = mid;
        }
        else if (nums[mid] > nums[end])
        {
            start = mid;
        }
        else
        {
            --end;
        }
    }

    if (nums[start] < nums[end])
    {
        return nums[start];
    }
    else
    {
        return nums[end];
    }
}

int main()
{
    int arr1[] = {4, 5, 6, 7, 0, 1, 2};
    int arr2[] = {2, 2, 2, 0, 1};
    vector<int> nums1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> nums2(arr2, arr2 + sizeof(arr2) / sizeof(int));

    const int result1 = findMin1(nums1);
    const int result2 = findMin2(nums2);

    cout << "Result1 is " << result1 << "\n";
    cout << "Result2 is " << result2 << endl;
}
