/**
 * @Author: Chacha 
 * @Date: 2018-12-16 21:53:13 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-12-17 23:05:18
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
#include <string>
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

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        vector<int> ret = Solution().BSTIterator(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
