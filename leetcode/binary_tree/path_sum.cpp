/**
 * @Author: Chacha 
 * @Date: 2019-02-15 15:12:02 
 * @Last Modified by: Chacha
 * @Last Modified time: 2019-02-16 11:55:40
 */

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**
     * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such 
     * that adding up all the values along the path equals the given sum.
     * 
     * Example:
     *  Given the below binary tree and sum = 22
     *              5
                   / \
                  4  8
                 /  / \
                11 13  4
               /  \     \
              7   2     1

     *  return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
     * 
     * Source:
     *  https://leetcode.com/problems/path-sum/
     */
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        if (root->val == sum && root->left == NULL && root->right == NULL) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

int main() {
    return 0;
}

