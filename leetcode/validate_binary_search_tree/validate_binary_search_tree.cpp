/**
 * @Author: Chacha 
 * @Date: 2018-12-09 21:54:02 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-12-09 22:25:43
 */

/***********************************************************************************
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * Assume a BST is defined as follows:
 *  1. The left subtree of a node contains only nodes with keys less than the node's key.
 *  2. The right subtree of a node contains only nodes with keys greater than the node's key.
 *  3. Both the left and right subtrees must also be binary search trees.
 * 
 * Example 1:
 *   Input:
 *   2
 *  / \
 * 1   3
 * Output: true
 * 
 * Example 2:
 *       5
 *      / \
 *     1  4
 *       / \
 *      3   6
 * Output: false
 * Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
 *              is 5 but its right child's value is 4.
 * 
 * Source: https://leetcode.com/problems/validate-binary-search-tree/
************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int lastVal;
bool firstNode = true;

// Preorder Traversal Ways
int isValidBST1(TreeNode* root) {
    
    if (root == NULL) {
        return true;
    }
    
    if (!isValidBST1(root->left)) {
        return false;
    }
    
    if (!firstNode && lastVal >= root->val) {
        return false;
    }

    firstNode = false;
    lastVal = root->val;

    if (!isValidBST1(root->right)) {
        return false;
    }

    return true;
}

// Divide & Conquer
int validateHelper(TreeNode* root, int lower, int upper) {
    
    if (root == NULL) {
        return true;
    }
    
    if (root->val <= lower || root->val >= upper) {
        bool right_max = root->val == INT_MAX && root->right == NULL;
        bool left_min = root->val == INT_MIN && root->left == NULL;
        
        if (!(right_max || left_min)) {
            return false;
        }
    }
    
    bool isLeftValidBST = validateHelper(root->left, lower, root->val);
    bool isRightValidBST = validateHelper(root->right, root->val, upper);

    return isLeftValidBST && isRightValidBST;
}

int isValidBST2(TreeNode* root) {

    if (root == NULL) return true;

    return validateHelper(root, INT_MIN, INT_MAX);
}

int main() {
    return 0;
}