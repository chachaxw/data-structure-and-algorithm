/**
 * @Author: Chacha 
 * @Date: 2018-11-24 13:31:24 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-11-25 13:30:40
 * @Source: https://leetcode.com/explore/learn/card/data-structure-tree
 */


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    int isFirst;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Pre-order Traversal
 * Pre-order traversal is to visit the root first. Then traverse the left subtree. 
 * Finally, traverse the right subtree. Here is an example:
 * https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/992/#pre-order-traversal
 */

// Recursive Way
void preorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    cout << root->val;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Divide & Conquer
vector<int> preorderTraversalDivideConquer(TreeNode* root) {
    vector<int> result;

    if (root == NULL) {
        return result;
    }

    vector<int> left = preorderTraversalDivideConquer(root->left);
    vector<int> right = preorderTraversalDivideConquer(root->right);

    result.push_back(root->val);
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());

    return result;
}

// Iterative Way 1
void iterativePreOrderTraversal1(TreeNode* root) {
    if(root == NULL) {
        cout << "The tree is NULL..." << endl;
    }

    stack<TreeNode*> nStack;
    TreeNode* node = root;

    // Start to traversal
    while(node != NULL || nStack.empty() != true) {
        // Output current subtree root node, and iterate to the last left node
        while(node != NULL){
            cout << node->val;
            nStack.push(node);
            node = node->left;
        }

        /**
         * While is end, and the top of the stack is the last left node,
         * and then start to pop the stack and output the right node.
         */
        if (nStack.empty() != true) {
            node = nStack.top();
            nStack.pop();
            node = node->right;
        }
    }
}

// Iterative Way 2
void iterativePreOrderTraversal2(TreeNode* root) {
    if(root == NULL) {
        cout << "The tree is NULL..." << endl;
    }

    stack<TreeNode*> nStack;
    nStack.push(root);

    TreeNode *node = root;

    while(nStack.empty() != true) {
        node = nStack.top();
        nStack.pop();
        cout << node->val;

        if (node->right != NULL) {
            nStack.push(node->right);
        }
        if (node->left != NULL) {
            nStack.push(node->left);
        }
    }
}


/**
 * In-order Traversal
 * In-order traversal is to traverse the left subtree first. 
 * Then visit the root. Finally, traverse the right subtree.
 * Here is an example:
 * https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/992/#in-order-traversal
 */

// Recursive Way
void inOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->val;
    inOrderTraversal(root->right);
}

// Divide & Conquer
vector<int> inOrderTraversalDivideConquer(TreeNode* root) {
    vector<int> result;

    if (root == NULL) {
        return result;
    }

    vector<int> left = inOrderTraversalDivideConquer(root->left);
    vector<int> right = inOrderTraversalDivideConquer(root->right);

    result.insert(result.end(), left.begin(), left.end());
    result.push_back(root->val);
    result.insert(result.end(), right.begin(), right.end());

    return result;
}

// Iterative Way
void iterativeInOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        cout << "The tree is NULL..." << endl;
    }

    stack<TreeNode*> nStack;
    TreeNode* node = root;

    while(node != NULL && nStack.empty() != true) {
        
        while(node != NULL){
            nStack.push(node);
            node = node->left;
        }
        
        if (nStack.empty() != true) {
            node = nStack.top();
            cout << node->val;
            nStack.pop();
            node = node->right;
        }
    }
}


/**
 * Post-order Traversal 
 * Post-order traversal is to traverse the left subtree first. 
 * Then traverse the right subtree. Finally, visit the root. 
 * Here is an animation to help you understand post-order traversal:
 * https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/992/#post-order-traversal
 */

// Recursive Way
void postOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->val;
}

// Divide & Conquer
vector<int> postOrderTraversalDivideConquer(TreeNode* root) {
    vector<int> result;

    if (root == NULL) {
        return result;
    }

    vector<int> left = postOrderTraversalDivideConquer(root->left);
    vector<int> right = postOrderTraversalDivideConquer(root->right);

    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    result.push_back(root->val);

    return result;
}

// Iterative Way 1
void iterativePostOrderTraversal1(TreeNode* root) {
    if (root == NULL) {
        cout << "The tree is NULL..." << endl;
    }

    stack<TreeNode*> nStack;
    TreeNode* node = root;
    
    while(root != NULL && nStack.empty() != true) {
        
        while(node != NULL){
            node->isFirst = 1; // When the node be accessed at first
            nStack.push(node);
            node = node->left;
        }
        
        if (nStack.empty() != true) {
            node = nStack.top();
            nStack.pop();

            if (node->isFirst == 1) {
                node->isFirst++;
                nStack.push(node);
                node = node->right;
            } else if (node->isFirst == 2) {
                cout << node->val;
                node = NULL;
            }
        }
    }
}

// Iterative Way 2
void iterativePostOrderTraversal2(TreeNode* root) {
    if (root == NULL) {
        cout << "The tree is NULL..." << endl;
    }

    stack<TreeNode*> nStack;
    TreeNode* cur;  // Current node
    TreeNode* prev = NULL;  // Previous node
    nStack.push(root);
    
    while(nStack.empty() != true){
        cur = nStack.top();

        /**
         * 1. The left and right child are NULL
         * 2. The children are output
         */
        if ((cur->left == NULL && cur->right == NULL) ||
            (prev != NULL && ((prev == cur->left) || prev == cur->right))
        ) {
            cout << cur->val;
            nStack.pop();
            prev = cur;
        } else {
            if (cur->right != NULL) {
                nStack.push(cur->right);
            }
            if (cur->left != NULL) {
                nStack.push(cur->left);
            }
        }
    }
}


int main() {
    /* code */
    return 0;
}
