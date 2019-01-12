/**
 * @Author: Chacha 
 * @Date: 2019-01-12 17:12:07 
 * @Last Modified by: Chacha
 * @Last Modified time: 2019-01-12 17:18:26
 */

#include<iostream>
#include<string>
using namespace std;

/** 
 * Definition for singly-linked list(单向链表)
 * Source: https://zh.wikipedia.org/wiki/链表
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * Sort a linked list in O(n log n) time using constant space complexity.
     * Example1: 
     *  Input: 4->2->1->3
     *  Output: 1->2->3->4
     * 
     * Example2:
     *  Input: -1->5->3->4->0
     *  Output: -1->0->3->4->5
     * 
     * Source: https://leetcode.com/problems/sort-list/
     * 
     */ 
    ListNode* sortList(ListNode* head) {
        return head;
    }
};

/* Function to print nodes in a given linked list */
void printList(struct ListNode *node) { 
    while (node != NULL) { 
        printf("%d ", node->val);
        node = node->next; 
    }
}

int main() {
    return 0;
}