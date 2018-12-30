/**
 * @Author: Chacha 
 * @Date: 2018-12-22 21:22:26 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-12-30 13:07:24
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
#include <stdio.h>
using namespace std;

int removeDuplicates1(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();

    int newIndex = 1;
    int len = nums.size();
    
    for(int i = 2; i < len; i++) {
        if (nums[newIndex] != nums[i] || nums[newIndex - 1] != nums[i]) {
            ++newIndex;
            nums[newIndex] = nums[i];
        }
    }

    return newIndex + 1;
}


/***********************************************************************************
 * Given a sorted array, remove the duplicates in place
 * such that each element appear only once and return the new length.
 * Given a sorted array, remove the duplicates in place
 * such that each element appear only once and return the new length.
 * For example, Given input array A = [1,1,2],
 * Your function should return length = 2, and A is now [1,2].
 * 
 * Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
************************************************************************************/
int removeDuplicates2(vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();
    
    int index = 0;

    for(int i = 1; i < nums.size(); i++) {
        
        if (nums[i] != nums[index]) {
            index++;
            nums[index] = nums[i];
        }
        
    }

    return index + 1;
}


int main() {
    int arr1[] = {0,0,1,1,1,1,2,3,3};
    int arr2[] = {0,0,1,1,1,2,2,3,3,4};
    vector<int> nums1(arr1, arr1 + sizeof(arr1)/sizeof(int));
    vector<int> nums2(arr2, arr2 + sizeof(arr2)/sizeof(int));

    int result1 = removeDuplicates1(nums1);
    int result2 = removeDuplicates2(nums2);

    cout << "Result1 is " << result1 << "\n";
    cout << "Result2 is " << result2 << "\n";

    for (int i = 0; i < nums1.size(); i++) {
        printf("%3d", nums1[i]);
    }

    cout << "\n";

    for (int i = 0; i < nums2.size(); i++) {
        printf("%3d", nums2[i]);
    }

    cout << endl;
}

