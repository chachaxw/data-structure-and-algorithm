/*
 * @Author: Chacha
 * @Date: 2018-12-30 13:12:05
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-03-05 10:45:20
 */

#include <iostream>
using namespace std;

/**
 * Struct definition for singly-linked list(单向链表结构体声明)
 * Source: https://zh.wikipedia.org/wiki/链表
 */
struct ListNodeA
{
    int val;         // 节点值
    ListNodeA *next; // 后继节点引用

    ListNodeA(int x) : val(x), next(NULL) {}
};

/**
 * Class definition for singly-linked list(单向链表类声明)
 */
class ListNodeB
{
public:
    int val;
    ListNodeB *next;

    ListNodeB(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

/**
 * Class definition for doubly-linked list(双向链表类声明)
 */
class DListNode
{
public:
    int val;
    DListNode *prev, *next;

    DListNode(int val)
    {
        this->val = val;
        this->prev = this->next = NULL;
    }
};

int main(int argc, char const *argv[])
{
    ListNodeA *node1 = new ListNodeA(4);
    ListNodeA *node2 = new ListNodeA(5);
    ListNodeA *node3 = new ListNodeA(1);

    cout << node1->val << std::endl;
    cout << node1->next << std::endl;

    return 0;
}
