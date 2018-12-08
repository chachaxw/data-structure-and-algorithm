/***********************************************************************************
 * Given a binary tree, find its maximum depth.The maximum depth is the number of 
 * nodes along the longest path from the root node down to the farthest leaf node.
 * Note: A leaf is a node with no children.
 * 
 * Given binary tree [3,9,20,null,null,15,7]
 *   3
 *  / \
 * 9  20
 *   /  \
 * 15   7
 * return its depth = 3.
 * 
 * Source: https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
************************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive Way
int maxDepthRecursive(TreeNode* root) {
    
    if (root == NULL) {
        return 0;
    }

    int left = maxDepthRecursive(root->left);
    int right = maxDepthRecursive(root->right);

    return 1 + max(left, right);    
}

// Iterative Way
int maxDepthIterative(TreeNode* root) {
    
    if (root == NULL) {
        return 0;
    }

    queue<TreeNode *> q;
    q.push(root);

    int max_depth = 0;
    
    while(!q.empty()){
        int size = q.size();
        for (int i = 0; i != size; i++) {
            TreeNode *node = q.front();
            q.pop();
            
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }

        ++max_depth;
    }
    
    return max_depth;
}

int main() {
    int arr[] = {3,9,20,NULL,NULL,15,7};
    const int maxDepth = maxDepthIterative(arr);

    cout << "Max depth is " << maxDepth << endl;
}
