/**
 * @Author: Chacha
 * @Date: 2018-12-25 22:53:20
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-03-04 23:19:23
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * 归并排序的核心：将两个有序对数组归并成一个更大对有序数组。
 * 通常做法为递归排序，并将两个不同的有序数组归并到第三个数组中。
 *
 * Source:
 *  https://zh.wikipedia.org/wiki/归并排序
 *  https://algs4.cs.princeton.edu/22mergesort/
 */

// 合并数组操作
template <typename T>

void merge(T nums[], int left, int mid, int right, T temp[])
{
    int i = left;    // 左序列起始位置
    int j = mid + 1; // 右序列起始位置
    int t = 0;       // 临时数组位置

    while (i <= mid && j <= right)
    {
        if (nums[i] <= nums[j]) // 如果左序列的值小于或等于右序列的值，就将左序列的那个值复制到临时数组temp里面，反之亦然。
        {
            temp[t++] = nums[i++];
        }
        else
        {
            temp[t++] = nums[j++];
        }
    }

    while (i <= mid) // 将左边剩余元素填充进temp中
    {
        temp[t++] = nums[i++];
    }

    while (j <= right) // 将右边剩余元素填充进temp中
    {
        temp[t++] = nums[j++];
    }

    t = 0;

    while (left <= right) // 将temp中的元素全部拷贝到原数组中
    {
        nums[left++] = temp[t++];
    }
};

// 排序操作
template <typename T>

void sort(T nums[], int left, int right, T temp[])
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;

    sort(nums, left, mid, temp);         // 左边归并排序，使得子序列有序
    sort(nums, mid + 1, right, temp);    // 右边归并排序，使得子序列有序
    merge(nums, left, mid, right, temp); // 将两个有序子数组合并操作
};

// 归并排序
template <typename T>

void mergeSort(T nums[], int len)
{
    int temp[len]; // 在排序前，先创建好一个长度等于原数组的临时数组，避免递归中频繁开辟空间
    sort(nums, 0, len - 1, temp);
};

int main()
{
    int nums[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int len = sizeof(nums) / sizeof(int);

    mergeSort(nums, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}
