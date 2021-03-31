/**
 * @Author: Chacha
 * @Date: 2018-11-24 13:31:24
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-03-30 14:30:46
 * @Source: 二叉树 https://leetcode-cn.com/leetbook/detail/data-structure-binary-tree/
 *          二叉树的遍历详解 https://shimo.im/docs/MAbjWlrqWqU1f72m
 */

/// 二叉树基本遍历，前序遍历，中序遍历，后续遍历

#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

/**
 * Definition for a binary tree node(定义一个二叉树).
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
 *    重复步骤1；若不为空，则将 P 的左孩子置为当前的节点P
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
 *
 * 根据中序遍历的顺序，对于任一节点，优先访问其左节点，而左节点又可以看作是一个根节点，然后继续访问其左节点子节点，
 * 直到遇到左孩子为为空的节点才进行访问，然后按相同的规则访问其右子树。
 *
 * 遍历步骤：
 * 1. 从根节点开始，开始遍历
 * 2. 递归输出直至最左，然后输出（中序先输出左孩子，而中序遍历第一个输出的是其最左叶子节点）
 * 3. 当到达最左节点的时候，访问右节点
 *
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

/**
 * Iterative Way(迭代方式)
 *
 * 处理过程：
 * 对于任一节点 P
 * 1. 若其左节点不为空，则将节点 P 入栈并将 P 的左节点置为当前的 P，然后对当前节点 P 再进行相同的处理
 * 2. 若其左节点为空，则取栈顶元素并进行出栈操作，访问该栈顶节点，然后将当前的 P 节点置为栈顶节点的右节点
 * 3. 直到P为NULL并且栈为空则遍历结束
 *
 */
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

/**
 * Iterative Way 1(迭代方式1)
 *
 * 第一种思路： 对于任一节点 P，将其入栈，然后沿其左子树一直往下搜索，直到搜索到没有左孩子节点，
 * 此时该节点出现在栈顶，但此时并不能将其出栈并访问。因为其右孩子节点还未被访问，所以接下来按照
 * 相同的规则将其右子树进行相同的处理，当访问完其右孩子节点时，该节点又出现在栈顶，此时可以将其
 * 出栈并访问。这样就保证了正确的访问顺序。可以看出，在这个过程中，每个节点都两次出现在栈顶，只有
 * 在第二次出现在栈顶时，才能访问它。因此需要多设置一个变量标识该节点该节点是否是第一次出现在栈顶。
 *
 */
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
            node->isFirst = 1; // 当前节点首次被访问
            nStack.push(node);
            node = node->left;
        }

        if (nStack.empty() != true)
        {
            node = nStack.top();
            nStack.pop();

            if (node->isFirst == 1) // 第一次出现在栈顶
            {
                node->isFirst++;
                nStack.push(node);
                node = node->right;
            }
            else if (node->isFirst == 2) // 第二次出现在栈顶
            {
                cout << node->val;
                node = NULL;
            }
        }
    }
}

/**
 * Iterative Way 2(迭代方式2)
 *
 * 第二种思路：要保证根节点在左孩子和右孩子访问之后才能访问，因此对于任一节点 P，先将其入栈。如果 P
 * 不存在左孩子和右孩子，则可以直接访问；或者 P 存在左孩子或者右孩子，但是其左孩子和右孩子都已经被访问
 * 过了，则同样可以访问该节点。若非上述两种情况，则将 P 的右孩子和左孩子依次入栈，这样就保证了每次取栈
 * 顶元素的时候，左孩子在右孩子前面被访问，左孩子和右孩子都在根节点前面被访问。
 *
 * 其实后序遍历中当前节点要是想被输出, 有三种情况：
 * 1. 其左右孩子均为NULL
 * 2. 其左孩子刚被输出，而其右孩子为NULL
 * 3. 其右孩子刚被输出
 *
 */
void iterativePostOrderTraversal2(TreeNode *root)
{
    if (root == NULL)
    {
        cout << "The tree is NULL..." << endl;
    }

    stack<TreeNode *> nStack;
    TreeNode *cur;         // 当前节点
    TreeNode *prev = NULL; // 前一次访问的节点
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
            // 由于栈是先进后出，因此先入右孩子, 再左孩子可以保证递归返回时先遍历左孩子
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
 * Binary Tree Level Order Traversal(二叉树层次遍历)
 */

/**
 * 递归方式1
 *
 * 打印当前树的第n层
 *
 * root: 树的根
 * n: 希望打印的层次
 * level: 当前递归层次
 *
 */
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

/**
 * 递归方式2
 *
 * 采用层次递减的方式，level = n为希望递归的层次，而层次每深入一次，level递减，当 level = 0 时，则说明递归至第n层
 *
 * root: 树的根
 * n: 希望打印的层次
 *
 */
int PrintLevel2(TreeNode *root, int level)
{

    if (root == NULL || level < 0)
    {
        return 0;
    }
    else if (level == 0)
    {
        cout << root->val;
        return 1;
    }
    else
    {
        return PrintLevel2(root->left, level - 1) + PrintLevel2(root->right, level - 1);
    }
}

/**
 * Iterative Way 1
 *
 * 双队列法：一个储存本层的节点，另一个储存下层的节点
 *
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
 * Iterative Way 2
 *
 * 双指针法：一个cur指向访问当层开始的节点，一个end指向访问当层结束节点的下一位置
 *
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
