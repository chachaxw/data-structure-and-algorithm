/*
 * @Author: Chacha 
 * @Date: 2018-11-27 09:28:23 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-11-27 18:38:01
 */

/**
 * Write an efficient algorithm that searches for a value in an m x n matrix. 
 * This matrix has the following properties:
 *  1. Integers in each row are sorted from left to right.
 *  2. The first integer of each row is greater than the last integer of the previous row.
 * Source: https://leetcode.com/problems/search-a-2d-matrix/
 * 
 * Example 1:
 * Input:
 * matrix = [
 *   [1,  3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * 
 * Example 2:
 * matrix = [
 *  [1,   3,  5,  7],
 *  [10, 11, 16, 20],
 *  [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

int searchMatrix(vector<vector<int> > matrix, int target) {
    if (matrix.empty() == true) {
        return false;
    }

    int ROW = matrix.size(), COL = matrix[0].size();
    int start = -1, end = ROW * COL, mid;

    while(start + 1 < end) {
        mid = start + (end - start) / 2;
        if (matrix[mid / COL][mid % COL] < target) {
            start = mid;
        } else {
            if (matrix[mid / COL][mid % COL] == target) {
                return true;
            }
            end = mid;
        }
    }

    return false;
}


int main() {
    int matrix[3][4] = {
        {1,  3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };

    vector<vector<int> > matrixVec(3, vector<int> (4));
    int result = searchMatrix(matrixVec, 3);
    cout << "Result is " << result << endl;
}

