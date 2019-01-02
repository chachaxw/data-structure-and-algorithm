/**
 * @Author: Chacha 
 * @Date: 2018-12-30 13:12:05 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-12-30 17:00:28
 */

#include<iostream>
using namespace std;

/** 
 * Struct definition for singly-linked list(单向链表)
 * Source: https://zh.wikipedia.org/wiki/链表
 */
struct ListNodeA {
    int val;
    ListNodeA *next;
    ListNodeA(int x) : val(x), next(NULL) {}
};

/**
 * Class definition for singly-linked list(单向链表)
 */
 class ListNodeB {
 public:
    int val;
    ListNodeB *next;
    ListNodeB(int val) {
        this->val = val;
        this->next = NULL;
    }
};

/**
 * Class definition for doubly-linked list(双向链表)
 */
class DListNode() {
public:
    int val;
    DListNode prev, next;
    DListNode(int val) {
        this.val = val;
        this.prev = this.next = NULL;
    }
}