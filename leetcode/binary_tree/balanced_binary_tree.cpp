/**
 * @Author: Chacha
 * @Date: 2019-01-03 17:07:54
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-03-30 15:47:16
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * 题目：
 * 给定一个二叉树，判断它是否是高度平衡的二叉树
 *
 * 平衡二叉树的定义：一个二叉树每个节点的左右两个子树的高度差的绝对值不超过1。
 *
 * 来源: https://leetcode-cn.com/problems/balanced-binary-tree
 *
 * 示例:
 * 给定二叉树 A={3,9,20,#,#,15,7}, B={3,#,20,15,7}
 *
 *  A)   3            B)    3
 *      / \                  \
 *      9  20                 20
 *        /  \                / \
 *       15   7              15  7
 *
 * 二叉树 A 是一个高度平衡的二叉树, 但 B 不是.
 *
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 方法二：自底向上的递归
 *
 * 题解：
 *
 * 来源：https://leetcode-cn.com/problems/balanced-binary-tree/solution/ping-heng-er-cha-shu-by-leetcode-solution/
 *
 * 自底向上递归类似于后序遍历，对于当前遍历到的节点，先递归地判断其左右子树是否平衡，再判断以当前节点为根的子树是否平衡。如果一棵子树是
 * 平衡的，则返回其高度（高度一定是非负整数），否则返回 -1.如果存在一棵子树不平衡，则整个二叉树一定不平衡。
 *
 */
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return maxDepth(root) >= 0;
    }

private:
    int maxDepth(TreeNode *root)
    {

        if (root == NULL)
            return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        if (leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1)
        {
            return -1;
        }

        return max(leftDepth, rightDepth) + 1;
    }
};

int main()
{
    return 0;
}
