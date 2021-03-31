/**
 * @Author: Chacha
 * @Date: 2019-01-14 18:30:40
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-03-29 14:10:58
 */

/**
 * 题目：
 * 给定一个二叉树，找出其最大深度。二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 *
 * 来源: https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
 *
 * 示例：
 * 给定二叉树 [3, 9, 20, null, null, 15, 7]
 *   3
 *  / \
 * 9  20
 *   /  \
 * 15   7
 * 返回它的最大深度 3.
 *
 */

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 题解：
 *
 * 来源：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/solution/er-cha-shu-de-zui-da-shen-du-by-leetcode-solution/
 *
 * 采用深度优先搜索方式，如果我们知道了左子树和右子树 l 和 r，那么该二叉树的最大深度即为：max(l, r) + 1，
 * 而左子树和右子树的最大深度又可以用同样的方式计算。具体而言，在计算当前二叉树的最大深度时，
 * 可以先递归计算出其左子树和右子树的最大深度，然后在 O(1)时间内计算出当前二叉树的最大深度。
 * 递归在访问到空节点时退出。
 *
 * 复杂度：
 * 时间复杂度：O(n)，n为二叉树节点个数。每个节点在递归中只被遍历一次。
 * 空间复杂度：O(height)，其中 height 表示二叉树的高度。递归函数需要栈空间，而栈空间取决于递归深度，因此空间复杂度等价于二叉树的高度。
 *
 */
// 递归方式，深度优先搜索(Recursive Way)
int maxDepthRecursive(TreeNode *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int left = maxDepthRecursive(root->left);
    int right = maxDepthRecursive(root->right);

    return 1 + max(left, right);
}

/**
 * 题解：
 *
 * 来源：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/solution/er-cha-shu-de-zui-da-shen-du-by-leetcode-solution/
 *
 * 采用广度优先搜索方式。我们用一个队列 q 来存放当前层的所有节点。每次拓展到下一层的时候，我们需要将队列里的所有节点都拿出来进行拓展，
 * 确保每次拓展完的时候队列里存放的是当前层的所有节点，即我们是一层一层的拓展，最后用一个变量 ans 来维护拓展的次数，该二叉树的最大深度
 * 即为 ans。
 *
 * 复杂度：
 * 时间复杂度：O(n)，其中 n 为二叉树的节点个数。
 * 空间复杂度：该方法空间的消耗取决于队列存储的元素数量，其在最坏情况下会达到 O(n)。
 *
 */
// 迭代方式(Iterative Way)
int maxDepthIterative(TreeNode *root)
{

    if (root == NULL)
    {
        return 0;
    }

    queue<TreeNode *> q;
    q.push(root);

    int max_depth = 0;

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i != size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }

        ++max_depth;
    }

    return max_depth;
}

TreeNode *insertLevelOrder(int arr[], TreeNode *root, int i, int n)
{
    // Base case for recursion
    if (i < n)
    {
        TreeNode *temp = new TreeNode(arr[i]);
        root = temp;

        // insert left child
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

        // insert right child
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

int main()
{
    int arr[] = {3, 9, 20, NULL, NULL, 15, 7};
    // const int maxDepth = maxDepthIterative();

    // cout << "Max depth is " << maxDepth << endl;
}
