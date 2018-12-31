/**
 * @Author: Chacha 
 * @Date: 2018-12-31 23:03:47 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-12-31 23:48:13
 */

/**
 * Reverse a linked list.
 * duplicate nodes from the list. The list is not sorted.
 * 
 * Example: 
 *  For linked list 1->2->3, the reversed linked list is 3->2->1
 * 
 * Source: https://www.kancloud.cn/kancloud/data-structure-and-algorithm-notes/73011
 *         https://leetcode.com/problems/reverse-linked-list/solution/
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
     * Operation steps:
     *  1. save next node of head
     *  2. change the next node of head to prev
     *  3. replace prev with head, wave forward
     *  4. replace the next node saved in the first step with head for the next iteration
     */
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        
        while(head != NULL){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        // fix head
        head = prev;
        return head;
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
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    ListNode* reversed = Solution().reverseList(head);
    
    printList(reversed);

    return 0;
}