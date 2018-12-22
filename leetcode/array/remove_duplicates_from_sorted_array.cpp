/**
 * @Author: Chacha 
 * @Date: 2018-12-22 21:22:26 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-12-22 22:44:48
 */

/***********************************************************************************
 * Remove Duplicates from Sorted Array II
 * Given a sorted array nums, remove the duplicates in-place such that 
 * duplicates appeared at most twice and return the new length. 
 * Do not allocate extra space for another array, you must do this 
 * by modifying the input array in-place with O(1) extra memory.
 * 
 * Example 1:
 *  Given nums = [1,1,1,2,2,3],
 *  Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
 *  It doesn't matter what you leave beyond the returned length.
 * 
 * Example 2:
 *  Given nums = [0,0,1,1,1,1,2,3,3],
 *  Your function should return length = 7, with the first seven elements of 
 *  nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
 *  It doesn't matter what values are set beyond the returned length.
 * 
 * Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums) {
    if (nums.size() <= 2) return nums.size();

    int newIndex = 1;
    int len = nums.size();
    
    for(int i = 2; i < len; i++) {
        if (nums[newIndex] != nums[i] || nums[newIndex - 1] != nums[i]) {
            ++newIndex;
            nums[newIndex] = nums[i];
        }
    }
    
    return newIndex;
}

void printVector(vector<int> &vec) {
    for(int i= 0; i < vec.size(); i++) {
        printf("%3d", vec[i]);
    }
    cout << endl;
}

int main() {
    int arr1[] = {0,0,1,1,1,1,2,3,3};
    vector<int> nums1(arr1, arr1 + sizeof(arr1)/sizeof(int));

    removeDuplicates(nums1);

    printVector(nums1);
}

