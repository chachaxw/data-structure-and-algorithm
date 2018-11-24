/**
 * @Author: Chacha 
 * @Date: 2018-11-24 19:05:12 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-11-24 20:00:37
 */

/**
 * The steps of binary search: 
 * 1. Let min = 0 , and let max = n where n is the highest possible index value;
 * 2. Find the average of min and max, round down so it’s an integer. This is our guess;
 * 3. If we guessed the number, stop, we got it;
 * 4. If guess is too low, set min equal to one more than guess;
 * 5. If guess is too high, set max equal to one less than guess;
 * 6. Go back to step two.
 */

#include <iostream>
using namespace std;

int binarySearch(int nums[], int target) {
    
    if (nums == NULL || sizeof(nums) == 0) {
        return -1;
    }

    int mid;
    int min = 0;
    int max = sizeof(nums) -1;
    
    while(min + 1 < max){
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

    if (nums[max] == target ) {
        return max;
    }

    return -1;
}

int main() {
    int nums[] = {1, 3, 4, 6, 7, 8, 10, 13, 14, 18, 19, 21, 24, 37, 40, 45, 71};
    int target = 10;

    int result = binarySearch(nums, target);

    cout << "Result is " << result << endl;
}