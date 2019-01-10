/**
 * @Author: Chacha 
 * @Date: 2019-01-10 20:22:11 
 * @Last Modified by: Chacha
 * @Last Modified time: 2019-01-10 21:45:48
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
     * Given a linked list and a value x, partition it such that 
     * all nodes less than x come before nodes greater than or equal to x.
     * You should preserve the original relative order of the nodes in each of the two partitions.
     * 
     * Example: 
     *  Input: head = 1->4->3->2->5->2, x = 3
     *  Output: 1->2->2->4->3->5
     * 
     * Source: https://leetcode.com/problems/partition-list/
     * 
     */
    ListNode* partitionList(ListNode* head, int x) {
        if (head == NULL) return NULL;

        ListNode* leftDummy = new ListNode(0);
        ListNode* rightDummy = new ListNode(0);
        ListNode* left = leftDummy;
        ListNode* right = rightDummy;
        
        while(head != NULL){
            if (head->val < x) {
                left->next = head;
                left = left->next;
            } else {
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }

        right->next = NULL;
        left->next = rightDummy->next;

        return leftDummy;
    }
};

/* Function to print nodes in a given linked list */
void printList(ListNode *node) { 
    while (node != NULL) { 
        printf("%d ", node->val); 
        node = node->next; 
    }
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    ListNode* result = Solution().partitionList(head, 3);
    printList(result);

    return 0;
}