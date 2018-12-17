/**
 * @Author: Chacha 
 * @Date: 2018-12-16 21:53:13 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-12-17 22:31:20
 */

/***********************************************************************************
 * Binary Search Tree Iterator
 * Implement an iterator over a binary search tree (BST). 
 * Your iterator will be initialized with the root node of a BST.
 * Calling next() will return the next smallest number in the BST.
 * 
 * Example
 *  For the following binary search tree, in-order traversal by using iterator is [1, 6, 10, 11, 12]
 * 
 *         10
 *       /    \
 *      1      11
 *       \       \
 *       6       12
 * 
 * Note: next() and hasNext() should run in average O(1) time and 
 * uses O(h) memory, where h is the height of the tree.
 * 
 * Source: https://leetcode.com/problems/binary-search-tree-iterator/
************************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class BSTIterator {
private:
    stack<TreeNode*> nStack;
    TreeNode* curt;
public:
    BSTIterator(TreeNode *root) {
        while(!nStack.empty()) {
            nStack.pop();
        }
        curt = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (curt != NULL || !nStack.empty());
    }

    /** @return the next smallest number */
    int next() {
        while (curt != NULL) {
            nStack.push(curt);
            curt = curt->left;
        }
        
        curt = nStack.top();
        nStack.pop();
        int val = curt->val;
        curt = curt->right;

        return val;
    }
}
