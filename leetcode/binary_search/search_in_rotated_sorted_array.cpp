/*
 * @Author: Chacha 
 * @Date: 2018-11-28 10:46:20 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-12-03 21:41:23
 */

#include <iostream>
#include <vector>
using namespace std;

/***********************************************************************************
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 *  Input: nums = [4,5,6,7,0,1,2], target = 0
 *  Output: 4
 * Example 2:
 *  Input: nums = [4,5,6,7,0,1,2], target = 3
 *  Output: -1
 * 
 * Source: https://leetcode.com/problems/search-in-rotated-sorted-array/
************************************************************************************/
int searchInRotatedSortedArray1(vector<int> nums, int target) {
    if (nums.empty()) {
        return -1;
    }

    int start = 0;
    int end = nums.size() -1;
    int mid; 
    
    while(start + 1 < end){
        // Prevent (left + right) overflow
        mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return mid;
        }

        if (nums[start] < nums[mid]) {
            // situation 1, numbers between start and mid are sorted
            if (nums[start] <= target && target < nums[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        } else {
            // situation 2, numbers between mid and end are sorted
            if (nums[mid] < target && target <= nums[end]) {
                start = mid;
            } else {
                end = mid;
            }
        }
    }

    if (nums[start] == target) {
        return start;
    }
    if (nums[end] == target) {
        return end;
    }

    return -1;
}

/***********************************************************************************
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 * You are given a target value to search. If found in the array return true, otherwise return false.
 * 
 * Example 1:
 *  Input: nums = [2,5,6,0,0,1,2], target = 0
 *  Output: true
 * 
 * Example 2:
 *  Input: nums = [2,5,6,0,0,1,2], target = 3
 *  Output: false
 * Source: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
************************************************************************************/
bool searchInRotatedSortedArray2(vector<int>& nums, int target) {
    if (nums.empty()) {
        return false;
    }

    int start = 0, end = nums.size() - 1, mid;

    while(start + 1 < end) {
        mid = start + (end - start) / 2;
        
        if (nums[mid] == target) {
            return true;
        }
        
        if (nums[start] < nums[mid]) {
            // situation 1, numbers between start and mid are sorted
            if (nums[start] <= target && target < nums[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        } else if (nums[start] > nums[mid]) {
            
            if (nums[mid] < target && target <= nums[end]) {
                start = mid;
            } else {
                end = mid;
            }
        } else {
            ++start;
        }
    }
    
    if (nums[start] == target || nums[end] == target) {
        return true;
    }
    
    return false;
}

int main() {
    int arr[] = {2, 5, 6, 0, 0, 1, 2};
    vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
    bool result = searchInRotatedSortedArray2(nums, 0);

    cout << "Result is " << result << endl;
}