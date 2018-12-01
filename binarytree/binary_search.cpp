/**
 * @Author: Chacha 
 * @Date: 2018-11-24 19:05:12 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-11-30 23:54:16
 */

/**
 * The steps of binary search: 
 * 1. Let min = 0 , and let max = n where n is the highest possible index value;
 * 2. Find the average of min and max, round down so it’s an integer. This is our guess;
 * 3. If we guessed the number, stop, we got it;
 * 4. If guess is too low, set min equal to one more than guess;
 * 5. If guess is too high, set max equal to one less than guess;
 * 6. Go back to step two.
 * 
 * 3 Parts of a Successful Binary Search
 * 1. Pre-processing - Sort if collection is unsorted.
 * 2. Binary Search - Using a loop or recursion to divide search space in half after each comparison.
 * 3. Post-processing - Determine viable candidates in the remaining space.
 */

#include <iostream>
#include <vector>
using namespace std;

// Binary search template
int binarySearch(vector<int>& nums, int target) {
    
    if (nums.empty()) {
        return -1;
    }

    int mid;
    int min = 0;
    int max = nums.size() -1;
    
    while(min + 1 < max){
        // Prevent (left + right) overflow
        mid = min + (max - min) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            min = mid;
        } else {
            max = mid;
        }
    }

    if (nums[min] == target) {
        return min;
    }

    if (nums[max] == target) {
        return max;
    }

    return -1;
}

/***********************************************************************************
 * Given a sorted array of integers, find the starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 * For example, Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].
************************************************************************************/

vector<int> binarySearchForRange(vector<int> nums, int target) {

    int start, end, mid;
    vector<int> bound(2);

    // Search for left bound
    start = 0;
    end = nums.size() - 1;
    
    while(start + 1 < end){
        // Prevent (left + right) overflow
        mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            end = mid;
        } else if (nums[mid] < target) {
            start = mid;
        } else {
            end = mid;
        }
    }
    if (nums[start] == target) {
        bound[0] = start;
    } else if (nums[end] == target) {
        bound[0] = end;
    } else {
        bound[0] = bound[1] = -1;
        return bound;
    }

    // Search for right bound
    while(start + 1 < end){
        // Prevent (left + right) overflow
        mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            start = mid;
        } else if (nums[mid] < target) {
            start = mid;
        } else {
            end = mid;
        }
    }

    if (nums[end] == target) {
        bound[1] = end;
    } else if (nums[start] == target) {
        bound[1] = start;
    } else {
        bound[0] = bound[1] = -1;
        return bound;
    }

    return bound;
}

/***********************************************************************************
 * Given a sorted array and a target value, return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in-order.
 * You may assume NO duplicates in the array.
 * Source: https://leetcode.com/problems/search-insert-position/
 * 
 * Example: 
 *  [1,3,5,6], 5 → 2
 *  [1,3,5,6], 2 → 1
 *  [1,3,5,6], 7 → 4
 *  [1,3,5,6], 0 → 0
************************************************************************************/
int searchInsert(vector<int> nums, int target) {
    if (nums.empty() == true) {
        return -1;
    }

    int start = -1, mid, end = nums.size();

    while(start + 1 < end) {
        mid = start + (end - start) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if(nums[mid] < target) {
            start = mid;
        } else {
            end = mid;
        }
    }

    return start + 1;
}


void printVector(vector<int> &vec) {
    for(int i= 0; i < vec.size(); i++) {
        printf("Vector is %3d", vec[i]);
        printf("\n");
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 3, 4, 6, 7, 8, 10, 10, 10, 13, 14, 18, 19, 21, 24, 37, 40, 45, 71};
    vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
    int target = 10;

    int result1 = binarySearch(nums, target);
    vector<int> result2 = binarySearchForRange(nums, target);

    cout << "Binary search result is " << result1 << "\n";

    printVector(result2);
}