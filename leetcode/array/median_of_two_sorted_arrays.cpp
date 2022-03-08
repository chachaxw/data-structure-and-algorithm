/**
 * @Author: Chacha
 * @Date: 2018-11-30 16:49:55
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-08 16:45:28
 */

#include <iostream>
#include <vector>

using namespace std;

/***********************************************************************************
 * There are two sorted arrays A and B of size m and n respectively.
 * Find the median of the two sorted arrays.
 * You may assume nums1 and nums2 cannot be both empty.
 *
 * Example 1:
 *  nums1 = [1, 3]
 *  nums2 = [2]
 *  The median is 2.0
 *
 * Example 2:
 *  nums1 = [1, 2]
 *  nums2 = [3, 4]
 *  The median is (2 + 3)/2 = 2.5
 *
 * Source: https://leetcode.com/problems/median-of-two-sorted-arrays/
 *         https://leetcode.com/problems/median-of-two-sorted-arrays/solution/
 ************************************************************************************/
int findKth(
    vector<int> &nums1,
    vector<int>::size_type nums1_start,
    vector<int> &nums2,
    vector<int>::size_type nums2_start,
    int k)
{
    if (nums1_start > nums1.size() - 1)
    {
        // 如果 nums1 数组已经穷尽了, 则只能返回 nums2 中的第 k 个元素
        return nums2[nums2_start + k - 1];
    }

    if (nums2_start > nums2.size() - 1)
    {
        // 如果 nums2 数组已经穷尽了, 则只能返回 nums1 中的第 k 个元素
        return nums1[nums1_start + k - 1];
    }

    if (k == 1)
    {
        // 如果 k = 1 则返回两个数组中最小的那个
        return nums1[nums1_start] < nums2[nums2_start] ? nums1[nums1_start] : nums2[nums2_start];
    }

    int nums1_key = nums1_start + k / 2 - 1 < nums1.size() ? nums1[nums1_start + k / 2 - 1] : INT_MAX;
    int nums2_key = nums2_start + k / 2 - 1 < nums2.size() ? nums2[nums2_start + k / 2 - 1] : INT_MAX;

    if (nums1_key > nums2_key)
    {
        return findKth(nums1, nums1_start, nums2, nums2_start + k / 2, k - k / 2);
    }
    else
    {
        return findKth(nums1, nums1_start + k / 2, nums2, nums2_start, k - k / 2);
    }
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.empty() && nums2.empty())
    {
        return 0;
    }

    vector<int> NonEmpty;

    if (nums1.empty())
    {
        NonEmpty = nums2;
    }

    if (nums2.empty())
    {
        NonEmpty = nums1;
    }

    if (!NonEmpty.empty())
    {
        vector<int>::size_type vec_len = NonEmpty.size();

        return vec_len % 2 == 0 ? (NonEmpty[vec_len / 2 - 1] + NonEmpty[vec_len / 2]) / 2 : NonEmpty[vec_len / 2];
    }

    vector<int>::size_type len = nums1.size() + nums2.size();

    if (len % 2 == 0)
    {
        return ((findKth(nums1, 0, nums2, 0, len / 2) + findKth(nums1, 0, nums2, 0, len / 2 + 1)) / 2);
    }
    else
    {
        return findKth(nums1, 0, nums2, 0, len / 2 + 1);
    }
}

int main()
{
    vector<int> nums1(1, 2);
    vector<int> nums2(3, 4);

    cout << "两个数组的中间值: " << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
