/**
 * @Author: Chacha 
 * @Date: 2018-12-27 23:20:14 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-12-27 23:34:01
 */

#include <iostream>
#include <vector>
using namespace std;

/***********************************************************************************
 * Given an array nums and a value val, remove all instances of that value in-place and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying 
 * the input array in-place with O(1) extra memory. The order of elements can be changed. 
 * It doesn't matter what you leave beyond the new length.
 * 
 * Example 1:
 *  Given nums = [3,2,2,3], val = 3,
 *  Your function should return length = 2, with the first two elements of nums being 2.
 *  It doesn't matter what you leave beyond the returned length.
 * 
 * Example 2:
 *  Given nums = [0,1,2,2,3,0,4,2], val = 2,
 *  Your function should return length = 5, with the first five elements 
 *  of nums containing 0, 1, 3, 0, and 4.
 *  Note that the order of those five elements can be arbitrary.
 *  It doesn't matter what values are set beyond the returned length.
 * 
 * Source: https://leetcode.com/problems/remove-element/
 * 
************************************************************************************/

int removeElement(vector<int> &nums, int val) {
    vector<int>::iterator iter = nums.begin();
    for(; iter < nums.end(); ++iter) {
        if (*iter == val) {
            iter = nums.erase(iter);
            --iter;
        }
    }

    return nums.size();
}

int main() {
    int arr[] = {0,0,1,1,1,1,2,3,3};
    vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));

    int result = removeElement(nums, 1);

    cout << "Result is " << result << endl;

    return 0;
}