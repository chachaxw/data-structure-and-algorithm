/*
 * @Author: Chacha 
 * @Date: 2018-11-26 11:11:37 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-11-26 13:22:07
 */

/**
 * Implement int sqrt(int x).
 * Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
 * Since the return type is an integer, the decimal digits are truncated 
 * and only the integer part of the result is returned.
 * Source: https://leetcode.com/problems/sqrtx/
 * 
 * Example 1:
 *  Input: 4 
 *  Output: 2
 * 
 * Example 2:
 *  Input: 8
 *  Output: 2
 *  Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
 */

#include <iostream>
using namespace std;

int sqrt(int x) {
    if (x < 0) {
        return -1;
    } else if(x == 0) {
        return 0;
    }

    long start = 1;
    long end = x;
    long mid;

    while(start + 1 < end) {
        mid = start + (end - start) / 2;

        if (mid * mid == x) {
            return mid;
        } else if(mid * mid > x) {
            end = mid;
        } else {
            start = mid;
        }
    }

    return start;
}

// Babylonian method for finding square roots
int sqrtByBabylonian(int x) {
    if (x == 0) {
        return 0;
    }

    double preSqrt, curSqrt = x, xFloat = x;
    while(true) {
        preSqrt = curSqrt;
        curSqrt = (curSqrt + xFloat / curSqrt) / 2;

        if (preSqrt == curSqrt) {
            return curSqrt;
        }
    }
}

int main() {
    int result1 = sqrt(8);
    int result2 = sqrtByBabylonian(10);
    cout << "Result1 is " << result1 << "\n";
    cout << "Result2 is " << result2 << endl;
}
