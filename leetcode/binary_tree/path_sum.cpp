/**
 * @Author: Chacha
 * @Date: 2019-02-15 15:12:02
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-11 19:25:50
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
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
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return false;
        if (root->val == sum && root->left == NULL && root->right == NULL)
            return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    TreeNode *n1 = new TreeNode(4);
    TreeNode *n2 = new TreeNode(8);
    TreeNode *n3 = new TreeNode(11);
    TreeNode *n4 = new TreeNode(13);
    TreeNode *n5 = new TreeNode(4);
    TreeNode *n6 = new TreeNode(7);
    TreeNode *n7 = new TreeNode(2);
    TreeNode *n8 = new TreeNode(1);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n5->right = n8;

    Solution s;

    cout << "Has path sum " << s.hasPathSum(root, 21) << endl;
    cout << "Has path sum " << s.hasPathSum(root, 22) << endl;

    return 0;
}
