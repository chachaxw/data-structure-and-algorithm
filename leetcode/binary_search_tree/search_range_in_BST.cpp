/**
 * @Author: Chacha
 * @Date: 2018-12-19 22:21:32
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-03-26 18:00:40
 */

/***********************************************************************************
 * Given a binary search tree and a range [k1, k2], return all elements in the given range.
 *
 * Example:
 *  If k1 = 10 and k2 = 22, then your function should return [12, 20, 22].
 *     20
 *    /  \
 *   8   22
 *  / \
 * 4  12
 *
 * Source: https://www.lintcode.com/problem/search-range-in-binary-search-tree/description
************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder_defs(vector<int> &ret, TreeNode *root, int k1, int k2)
{

    if (root == NULL)
    {
        return;
    }

    inorder_defs(ret, root->left, k1, k2);

    if ((root->val >= k1) && (root->val <= k2))
    {
        ret.push_back(root->val);
    }

    inorder_defs(ret, root->left, k1, k2);
}

vector<int> searchRange(TreeNode *root, int k1, int k2)
{
    vector<int> result;
    inorder_defs(result, root, k1, k2);

    return result;
}

int main()
{
    return 0;
}
