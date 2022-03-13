/*
 * @Author: Chacha
 * @Date: 2022-03-11 19:43:07
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-12 22:22:08
 */

/**
 * 来源：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
 *
 * 二叉树层序遍历
 *
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。（即逐层地，从左到右访问所有节点）。
 *
 * 示例 1：
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[9,20],[15,7]]
 *
 *     3
 *    / \
 *    9  20
 *      /  \
 *     15   7
 *
 *
 * 示例 2：
 * 输入：root = [1]
 * 输出：[[1]]
 *
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node(定义一个二叉树).
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    /* data */
public:
    vector<vector<int>> levelOrder(TreeNode *root);
};

/**
 * Binary Tree Level Order Traversal(二叉树层次遍历)
 *
 * 广度优先搜索：
 * 1. 首先根元素入队
 * 2. 当队列不为空的时候:
 *    a. 求当前队列的长度Si
 *    b. 依次从队列中取Si个元素进行拓展，然后进入下一次迭代
 * 每次取 Si 个元素。在上述过程中的第 i 次迭代就得到了二叉树的第 i 层的 Si 个元素。
 * 我们观察这个算法，可以归纳出这样的循环不变式：第 i 次迭代前，队列中的所有元素就是第 i 层的所有元素，
 * 并按照从左向右的顺序排列。证明它的三条性质（你也可以把它理解成数学归纳法）：
 * 1. 初始化：i = 1 的时候，队列里面只有 root，是唯一的层数为 1 的元素，所以也显然满足「从左向右排列」；
 * 2. 保持：如果 i = k 时性质成立，即第 k 轮中出队 Sk 的元素是第 k 层的所有元素，并且顺序从左到右。
 *    因为对树进行广度优先搜索的时候由低 k 层的点拓展出的点一定也只能是 k+1 层的点，并且 k+1 层的点只能由第 k 层的点拓展到，
 *    所以由这 Sk 个点能拓展到下一层所有的 Sk+1 个点。又因为队列的先进先出（FIFO）特性，
 *    既然第 k 层的点的出队顺序是从左向右，那么第 k+1 层也一定是从左向右。
 * 3. 终止：因为该循环不变式是正确的，所以按照这个方法迭代之后每次迭代得到的也就是当前层的层次遍历结果。
 *
 * 时间复杂度：每个点进队出队各一次，故渐进时间复杂度为 O(n)
 * 空间复杂度：队列中元素的个数不超过 n 个，故渐进空间复杂度为 O(n)
 *
 * 题解：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-de-ceng-xu-bian-li-by-leetcode-solution/
 *
 */
vector<vector<int>> Solution::levelOrder(TreeNode *root)
{
    vector<vector<int>> ret;
    if (!root)
        return ret;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int currentLevelSize = q.size();

        ret.push_back(vector<int>());

        for (int i = 1; i <= currentLevelSize; i++)
        {
            auto node = q.front();
            q.pop();
            ret.back().push_back(node->val);

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
    }

    return ret;
}

void print(vector<vector<int>> a)
{
    vector<vector<int>>::iterator p1;
    vector<int>::iterator p2;

    for (p1 = a.begin(); p1 != a.end(); p1++)
    {
        for (p2 = p1->begin(); p2 != p1->end(); p2++)
        {
            cout << "[" << *p2 << "]";
        }
        cout << endl;
    }

    cout << endl;
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(3);
    TreeNode *n1 = new TreeNode(9);
    TreeNode *n2 = new TreeNode(20);
    TreeNode *n3 = new TreeNode(15);
    TreeNode *n4 = new TreeNode(7);

    root->left = n1;
    root->right = n2;
    n2->left = n3;
    n2->right = n4;

    Solution s;
    vector<vector<int>> result = s.levelOrder(root);

    print(result); // 打印出：[3], [9][20], [15][7]

    return 0;
}
