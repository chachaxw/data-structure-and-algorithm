/**
 * @Author: Chacha 
 * @Date: 2019-01-03 17:07:54 
 * @Last Modified by: Chacha
 * @Last Modified time: 2019-01-03 18:01:39
 */

#include<iostream>
#include<vector>
using namespace std;

/**
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as a binary tree in which 
 * the depth of the two subtrees of every node never differ by more than 1.
 * 
 * Example:
 *  Given binary tree A={3,9,20,#,#,15,7}, B={3,#,20,15,7}
 *  A)   3            B)    3
 *      / \                  \
 *      9  20                 20
 *        /  \                / \
 *       15   7              15  7
 * 
 * The binary tree A is a height-balanced binary tree, but B is not.
 * 
 * Source: https://leetcode.com/problems/balanced-binary-tree/
 */

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return (-1 != maxDepth(root));
    }

private:
    int maxDepth(TreeNode* root) {
        
        if (root == NULL) return 0;
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        if (leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1) {
            return -1;
        }

        return max(leftDepth, rightDepth) + 1;
    }
}

int main() {
    return 0;
}
