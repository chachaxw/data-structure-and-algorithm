/**
 * @Author: Chacha
 * @Date: 2019-02-16 13:26:00
 * @Last Modified by: Chacha
 * @Last Modified time: 2019-02-16 18:30:38
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

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        queue<TreeNode *> q;
        q.push(root);

        int max_depth = 0;

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
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
};

int main()
{
    return 0;
}
