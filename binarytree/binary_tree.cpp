/**
 * @Author: Chacha
 * @Date: 2018-11-24 13:31:24
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-03-09 19:39:19
 * @Source: https://leetcode.com/explore/learn/card/data-structure-tree
 */

#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    int isFirst;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Pre-order Traversal (前序遍历)
 * Pre-order traversal is to visit the root first. Then traverse the left subtree.
 * Finally, traverse the right subtree. Here is an example:
 * https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/992/#pre-order-traversal
 *
 * 访问顺序：根节点->左节点->右节点
 *
 * 遍历步骤：
 * 1. 从根节点开始遍历，并输出（前序遍历首先输出根）
 * 2. 递归输出直至最左（前序遍历根后面输出的是左孩子）
 * 3. 当达到最左节点的时候，访问右节点
 *
 */

// Recursive Way(递归方式)
void preorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->val;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Divide & Conquer(分治方式)
vector<int> preorderTraversalDivideConquer(TreeNode *root)
{
    vector<int> result;

    if (root == NULL)
    {
        return result;
    }

    vector<int> left = preorderTraversalDivideConquer(root->left);
    vector<int> right = preorderTraversalDivideConquer(root->right);

    result.push_back(root->val);
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());

    return result;
}

/**
 * Iterative Way 1(迭代方式1)
 *
 * 处理过程：
 * 1. 访问节点 P，并将节点 P 入栈
 * 2. 判断节点 P 的左孩子是否为空，若为空，则取栈顶的节点并进行出栈操作，并将栈顶节点的右孩子置为当前的节点 P，
 *    循环至1；若不为空，则将 P 的左孩子置为当前的节点P
 * 3. 直到 P 为 NULL并且栈为空，则遍历结束
 *
 */
void iterativePreOrderTraversal1(TreeNode *root)
{
    if (root == NULL)
    {
        cout << "The tree is NULL..." << endl;
    }

    stack<TreeNode *> nStack;
    TreeNode *node = root;

    while (node != NULL || nStack.empty() != true)
    {
        // 输出当前子树当根节点，然后递归至最左
        while (node != NULL)
        {
            cout << node->val;
            nStack.push(node);
            node = node->left;
        }

        /**
         * 当循环结束时，当前栈顶节点已经是最左节点
         * 此时递归开始返回，开始出栈，并输出节点当右节点。
         */
        if (nStack.empty() != true)
        {
            node = nStack.top();
            nStack.pop();
            node = node->right;
        }
    }
}

// Iterative Way 2
void iterativePreOrderTraversal2(TreeNode *root)
{
    if (root == NULL)
    {
        cout << "The tree is NULL..." << endl;
    }

    stack<TreeNode *> nStack;
    nStack.push(root);

    TreeNode *node = root;

    while (nStack.empty() != true)
    {
        node = nStack.top();
        nStack.pop();
        cout << node->val;

        if (node->right != NULL)
        {
            nStack.push(node->right);
        }
        if (node->left != NULL)
        {
            nStack.push(node->left);
        }
    }
}

/**
 * In-order Traversal (中序遍历)
 * In-order traversal is to traverse the left subtree first.
 * Then visit the root. Finally, traverse the right subtree.
 * Here is an example:
 * https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/992/#in-order-traversal
 *
 * 访问顺序：左节点->根节点->右节点
 */

// Recursive Way(递归方式)
void inOrderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->val;
    inOrderTraversal(root->right);
}

// Divide & Conquer(分治方式)
vector<int> inOrderTraversalDivideConquer(TreeNode *root)
{
    vector<int> result;

    if (root == NULL)
    {
        return result;
    }

    vector<int> left = inOrderTraversalDivideConquer(root->left);
    vector<int> right = inOrderTraversalDivideConquer(root->right);

    result.insert(result.end(), left.begin(), left.end());
    result.push_back(root->val);
    result.insert(result.end(), right.begin(), right.end());

    return result;
}

// Iterative Way(迭代方式)
void iterativeInOrderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        cout << "The tree is NULL..." << endl;
    }

    stack<TreeNode *> nStack;
    TreeNode *node = root;

    while (node != NULL && nStack.empty() != true)
    {

        while (node != NULL)
        {
            nStack.push(node);
            node = node->left;
        }

        if (nStack.empty() != true)
        {
            node = nStack.top();
            cout << node->val;
            nStack.pop();
            node = node->right;
        }
    }
}

/**
 * Post-order Traversal (后序遍历)
 * Post-order traversal is to traverse the left subtree first.
 * Then traverse the right subtree. Finally, visit the root.
 * Here is an animation to help you understand post-order traversal:
 * https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/992/#post-order-traversal
 *
 * 访问顺序：左节点->右节点->根节点
 */

// Recursive Way(递归方式)
void postOrderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->val;
}

// Divide & Conquer(分治方式)
vector<int> postOrderTraversalDivideConquer(TreeNode *root)
{
    vector<int> result;

    if (root == NULL)
    {
        return result;
    }

    vector<int> left = postOrderTraversalDivideConquer(root->left);
    vector<int> right = postOrderTraversalDivideConquer(root->right);

    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    result.push_back(root->val);

    return result;
}

// Iterative Way 1(迭代方式1)
void iterativePostOrderTraversal1(TreeNode *root)
{
    if (root == NULL)
    {
        cout << "The tree is NULL..." << endl;
    }

    stack<TreeNode *> nStack;
    TreeNode *node = root;

    while (root != NULL && nStack.empty() != true)
    {

        while (node != NULL)
        {
            node->isFirst = 1; // When the node be accessed at first
            nStack.push(node);
            node = node->left;
        }

        if (nStack.empty() != true)
        {
            node = nStack.top();
            nStack.pop();

            if (node->isFirst == 1)
            {
                node->isFirst++;
                nStack.push(node);
                node = node->right;
            }
            else if (node->isFirst == 2)
            {
                cout << node->val;
                node = NULL;
            }
        }
    }
}

// Iterative Way 2(迭代方式2)
void iterativePostOrderTraversal2(TreeNode *root)
{
    if (root == NULL)
    {
        cout << "The tree is NULL..." << endl;
    }

    stack<TreeNode *> nStack;
    TreeNode *cur;         // Current node
    TreeNode *prev = NULL; // Previous node
    nStack.push(root);

    while (nStack.empty() != true)
    {
        cur = nStack.top();

        /**
         * 1. The left and right child are NULL
         * 2. The children are output
         */
        if ((cur->left == NULL && cur->right == NULL) ||
            (prev != NULL && ((prev == cur->left) || prev == cur->right)))
        {
            cout << cur->val;
            nStack.pop();
            prev = cur;
        }
        else
        {
            if (cur->right != NULL)
            {
                nStack.push(cur->right);
            }
            if (cur->left != NULL)
            {
                nStack.push(cur->left);
            }
        }
    }
}

/**
 * Binary Tree Level Order Traversal
 * Source: https://shimo.im/docs/MAbjWlrqWqU1f72m/
 */
// Recursive Way 1
int PrintLevel1(TreeNode *root, int n, int level)
{

    if (root == NULL || level < 0)
    {
        return 0;
    }
    else if (level == n)
    {
        cout << root->val;
        return 1;
    }
    else
    {
        return PrintLevel1(root->left, n, level + 1) + PrintLevel1(root->right, n, level + 1);
    }
}

// Recursive Way 2
int PrintLevel2(TreeNode *root, int n, int level)
{

    if (root == NULL || level < 0)
    {
        return 0;
    }
    else if (level == n)
    {
        cout << root->val;
        return 1;
    }
    else
    {
        return PrintLevel2(root->left, n, level - 1) + PrintLevel2(root->right, n, level - 1);
    }
}

/**
 * Iterative Way 1
 * Use two queues, one queue for current level nodes and another for next level nodes
 */
void LevelOrderDev(TreeNode *root)
{
    deque<TreeNode *> qFirst, qSecond;
    qFirst.push_back(root);

    while (qFirst.empty() != true)
    {
        while (qFirst.empty() != true)
        {
            TreeNode *temp = qFirst.front();
            qFirst.pop_front();

            cout << temp->val;

            if (temp->left != NULL)
            {
                qSecond.push_back(temp->left);
            }

            if (temp->right != NULL)
            {
                qSecond.push_back(temp->right);
            }
        }
        cout << endl;
        qFirst.swap(qSecond);
    }
}

/**
 * Iterative Way 1
 * Use two pointers, one pointer for current level nodes and another for next level nodes
 */
void LevelOrderUsePoint(TreeNode *root)
{
    vector<TreeNode *> vec;
    vec.push_back(root);

    int cur = 0;
    int end = 1;

    while (cur < vec.size())
    {
        end = vec.size();

        while (cur < end)
        {
            cout << vec[cur]->val;

            if (vec[cur]->left != NULL)
            {
                vec.push_back(vec[cur]->left);
            }

            if (vec[cur]->right != NULL)
            {
                vec.push_back(vec[cur]->right);
            }

            cur++;
        }
        cout << endl;
    }
}

int main()
{
    /* code */
    return 0;
}
