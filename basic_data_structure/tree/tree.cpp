/*
 * @Author: Chacha
 * @Date: 2021-03-05 19:11:18
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-03-07 22:08:29
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * 树是一种非线性数据结构，根据子节点数量可分为 「二叉树」 和 「多叉树」，最顶层的节点称为「根节点 root」。
 * 以二叉树为例，每个节点包含三个成员变量：「值 val」、「左子节点 left」、「右子节点 right」 。
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * BFS - Template 1
 * Return the length of the shortest path between root and target node.
 *
 * 1. As shown in the code, in each round, the nodes in the queue are the nodes which are waiting to be processed.
 * 2. After each outer while loop, we are one step farther from the root node.
 *    The variable step indicates the distance from the root node and the current node we are visiting.
 */

/*
int BFS(TreeNode root, TreeNode target)
{
    queue<TreeNode> queue; // store all nodes which are waiting to be processed
    int step = 0;          // number of steps needed from root to current node

    initialize
    add root to queue;
    // BFS
    while (queue is not empty)
    {
        step = step + 1;
        // iterate the nodes which are already in the queue
        int size = queue.size();
        for (int i = 0; i < size; ++i)
        {
            Node cur = the first node in queue;
            return step if cur is target;
            for (Node next : the neighbors of cur)
            {
                add next to queue;
            }
            remove the first node from queue;
        }
    }
    return -1; // there is no path from root to target
}
*/

/**
 * BFS - Template 2
 * Return the length of the shortest path between root and target node.
 *
 * There are two cases you don't need the hash set used:
 *  1. You are absolutely sure there is no cycle, for example, in tree traversal;
 *  2. You do want to add the node to the queue multiple times.
 */

/*
int BFS(TreeNode root, TreeNode target)
{
    queue<TreeNode> queue; // store all nodes which are waiting to be processed
    int step = 0;          // number of steps needed from root to current node

    initialize
    add root to queue;
    // BFS
    while (queue is not empty)
    {
        step = step + 1;
        // iterate the nodes which are already in the queue
        int size = queue.size();
        for (int i = 0; i < size; ++i)
        {
            Node cur = the first node in queue;
            return step if cur is target;
            for (Node next : the neighbors of cur)
            {
                add next to queue;
            }
            remove the first node from queue;
        }
    }

    return -1; // there is no path from root to target
}
*/
