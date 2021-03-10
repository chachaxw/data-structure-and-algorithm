/**
 * @Author: Chacha
 * @Date: 2018-12-29 23:03:23
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-03-10 10:01:20
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Source:
 *  https://zh.wikipedia.org/wiki/快速排序
 *  https://algs4.cs.princeton.edu/23quicksort/
 *
 * Time Complexity: O(n log n) (the badest situation is O(n^2))
 * Space Complexity: O(log n)
 *
 * The solution:
 *  1. Find a pivot element x;
 *  2. Partition();
 *  3. Recursive previous two steps
 */

// Pseudocode
// function quicksort(arr) {
//     var list less, pivotList, greater
//     if length(arr) <= 1 {
//         return arr;
//     } else {
//         select a pivot value pivot from arr
//         for each x in arr except the pivot element
//             if x < pivot then add x to less
//             if x >= pivot then add x to greater
//         add pivot to pivotList
//         return concatenate(quicksort(less), pivotList, quickSort(greater));
//     }
// }

// In-place recursive way1
template <typename T>
void quickSortRecursive1(T nums[], int start, int end)
{

    if (start >= end)
        return;

    T mid = nums[end];
    int left = start, right = end - 1;

    while (left < right)
    {

        while (nums[left] < mid && left < right)
            left++;

        while (nums[right] >= mid && left < right)
            right--;

        swap(nums[left], nums[right]);
    }

    if (nums[left] >= nums[end])
    {
        swap(nums[left], nums[end]);
    }
    else
    {
        left++;
    }

    quickSortRecursive1(nums, start, left - 1);
    quickSortRecursive1(nums, left + 1, end);
}

// In-place recursive way2
template <typename T>
void quickSortRecursive2(T nums[], int start, int end)
{

    if (start >= end)
        return;

    T mid = start;

    for (int i = start + 1; i <= end; i++)
    {
        if (nums[i] < nums[start])
        {
            mid++;
            swap(nums[mid], nums[i]);
        }
    }

    // Swap between nums[mid] and nums[i], put pivot in the mid
    swap(nums[mid], nums[start]);

    quickSortRecursive2(nums, start, mid - 1);
    quickSortRecursive2(nums, mid + 1, end);
}

int main()
{
    int nums[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int len = sizeof(nums) / sizeof(int);

    // quickSortRecursive1(nums, 0, len - 1);
    quickSortRecursive2(nums, 0, len - 1);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}
