/**
 * @Author: Chacha
 * @Date: 2018-12-01 17:56:42
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-03-26 18:00:12
 */

#include <iostream>
#include <vector>

using namespace std;

/***********************************************************************************
 * A peak element is an element that is greater than its neighbors.
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 * You may imagine that nums[-1] = nums[n] = -∞.
 *
 * Example 1:
 *  Input: nums = [1,2,3,1]
 *  Output: 2
 *  Explanation: 3 is a peak element and your function should return the index number 2.
 *
 * Example 2:
 *  Input: nums = [1,2,1,3,5,6,4]
 *  Output: 1 or 5
 *  Explanation: Your function can return either index number 1 where the peak element is 2,
                 or index number 5 where the peak element is 6.
 *
 * Source: https://leetcode.com/problems/find-peak-element/
************************************************************************************/

// The first way
int findPeakElement1(vector<int> nums)
{
    if (nums.empty())
    {
        return -1;
    }

    int start = 0, mid, end = nums.size() - 1;

    while (start + 1 < end)
    {
        mid = start + (end - start) / 2;
        if (nums[mid] < nums[mid - 1])
        {
            end = mid;
        }
        else if (nums[mid] < nums[mid + 1])
        {
            start = mid;
        }
        else
        {
            return mid;
        }
    }

    mid = nums[start] > nums[end] ? start : end;
    return mid;
}

// The second way
int findPeakElement2(vector<int> nums)
{
    if (nums.empty())
    {
        return -1;
    }

    for (int i = 0; i < nums.size() - 1; i++)
    {

        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
        {
            return i;
        }
    }

    return nums.size() <= 1 || nums[0] > nums[1] ? 0 : nums.size() - 1;
}

/***********************************************************************************
 * 一个整数矩阵有如下一些特性：
 * 相邻的整数都是不同的 矩阵有 n 行 m 列。 对于所有的 i < m, 都有 A0 < A1 && An - 2 > An - 1.
 * 对于所有的 j < n, 都有 Aj < Aj && Aj > Aj. 我们定义一个位置 P 是一个峰，
 * 如果有 Aj > Aj+1 && Aj > Aj-1 && Aj > Aj && Aj > Aj。
 * 找出该矩阵的一个峰值元素，返回他的坐标
 *
 *  1     2     3     4     5
 *  16    41    25    22    6
 *  15    17    24    21    7
 *  14    18    19    20    8
 *  13    12    11    10    9
 *
************************************************************************************/
int findPeak(int row, vector<vector<int>> matrix)
{
    int peak = 0;

    for (int i = 0; i < matrix[row].size(); i++)
    {

        if (matrix[row][i] > matrix[row][peak])
        {
            peak = i;
        }
    }

    return peak;
}

vector<int> findPeakII(vector<vector<int>> matrix)
{
    vector<int> result;

    const int ROW = matrix.size(), COL = matrix[0].size();
    int start = 0, mid, end = ROW * COL - 1;

    while (start + 1 < end)
    {
        mid = start + (end - start) / 2;
        int col = findPeak(mid, matrix);

        if (matrix[mid][col] < matrix[mid + 1][col])
        {
            start = mid;
        }
        else if (matrix[mid][col] > matrix[mid - 1][col])
        {
            end = mid;
        }
        else
        {
            result.push_back(mid);
            result.push_back(col);

            return result;
        }
    }

    return result;
}

// Print vector value
void printVector(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("Vector is %3d", vec[i]);
        printf("\n");
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 1, 3, 5, 6, 4};
    int arr1[5][5] = {
        {1, 2, 3, 4, 5},
        {16, 41, 25, 22, 6},
        {15, 17, 24, 21, 7},
        {14, 18, 19, 20, 8},
        {13, 12, 11, 10, 9},
    };

    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    vector<vector<int>> matrix(5, vector<int>(5));
    int result1 = findPeakElement1(nums);
    int result2 = findPeakElement2(nums);
    vector<int> result3 = findPeakII(matrix);

    cout << "Result1 is " << result1 << "\n";
    cout << "Result2 is " << result2 << endl;

    printVector(result3);
}
