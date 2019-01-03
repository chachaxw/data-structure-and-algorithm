/**
 * @Author: Chacha 
 * @Date: 2018-11-27 09:28:23 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-12-03 21:39:45
 */

/***********************************************************************************
 * Write an efficient algorithm that searches for a value in an m x n matrix. 
 * This matrix has the following properties:
 *  1. Integers in each row are sorted from left to right.
 *  2. The first integer of each row is greater than the last integer of the previous row.
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
 * Source: https://leetcode.com/problems/search-a-2d-matrix/
************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix1(vector<vector<int> > matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }

    const int ROW = matrix.size(), COL = matrix[0].size();
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

/***********************************************************************************
 * Write an efficient algorithm that searches for a value in an m x n matrix, 
 * return the occurrence of it.This matrix has the following properties:
 *  1. Integers in each row are sorted from left to right.
 *  2. Integers in each column are sorted from up to bottom.
 *  3. No duplicate integers in each row or column.
 * 
 * Example:
 *  [1, 3, 5, 7],
 *  [2, 4, 7, 8],
 *  [3, 5, 9, 10]
 * 
 * Given target = 3, return 2.
 * 
 * Source: https://leetcode.com/problems/search-a-2d-matrix-ii/
************************************************************************************/

bool searchMatrix2(vector<vector<int> >& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }

    const int ROW = matrix.size();
    const int COL = matrix[0].size();
    int row = 0, col = COL - 1;
    
    while(row < ROW && col >= 0){
        if (matrix[row][col] == target) {
            return true;
        } else if (target < matrix[row][col]) {
            --col;
        } else {
            ++row;
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
    int result1 = searchMatrix1(matrixVec, 10);
    bool result2 = searchMatrix2(matrixVec, 34);

    cout << "Result1 is " << result1 << "\n";
    cout << "Result2 is " << result2 << endl;
}

