/*
 * @Author: Chacha 
 * @Date: 2018-12-01 17:56:42 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-12-01 18:56:00
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
int findPeakElement1(vector<int> nums) {
    if (nums.empty()) {
        return -1;
    }

    int start = 0, mid, end = nums.size() - 1;
    
    while(start + 1 < end){
        mid = start + (end - start) / 2;
        if (nums[mid] < nums[mid - 1]) {
            end = mid;
        } else if (nums[mid] < nums[mid + 1]) {
            start = mid;
        } else {
            return mid;
        }
    }
    
    mid = nums[start] > nums[end] ? start : end;
    return mid;
}

// The second way
int findPeakElement2(vector<int> nums) {
    if (nums.empty()) {
        return -1;
    }

    for(int i = 0; i < nums.size() - 1; i++) {
        
        if (nums[i] > nums[i-1] && nums[i] > nums[i + 1]) {
            return i;
        }
        
    }

    return nums.size() <= 1 || nums[0] > nums[1] ? 0 : nums.size() - 1;
}

int main() {
    int arr[] = {1,2,1,3,5,6,4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    int result1 = findPeakElement1(nums);
    int result2 = findPeakElement2(nums);

    cout << "Result1 is " << result1 << "\n";
    cout << "Result2 is " << result2 << endl;
}