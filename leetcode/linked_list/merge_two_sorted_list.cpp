/**
 * @Author: Chacha 
 * @Date: 2019-01-06 22:50:09 
 * @Last Modified by: Chacha
 * @Last Modified time: 2019-01-06 23:13:13
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
     * Merge two sorted linked lists and return it as a new list.
     * The new list should be made by splicing together the nodes of the first two lists.
     * 
     * Example: 
     *  Given 1->3->8->11->15->null, 2->null
     *  return 1->2->3->8->11->15->null
     * 
     * Source: https://leetcode.com/problems/merge-two-sorted-lists/
     * 
     * Operation steps:
     *  1. Exception handling, included in dummy->next
     *  2. Create the dummy and lastNode nodes, let the lastNode pointed to dummy node
     *  3. Loop processing for non-empty l1, l2, linking the smaller of l1/l2 to lastNode->next, recursing lastNode
     *  4. one of the linked lists in l1/l2 is empty to exit the while loop, 
     *     and the non-empty list header is linked to lastNode->next
     *  5. Return dummy->next, which is the final head pointer
     */ 
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* lastNode = dummy;
        
        while(l1 != NULL && l2 != NULL){

            if (l1->val < l2->val) {
                lastNode->next = l1;
                l1 = l1->next;
            } else {
                lastNode->next = l2;
                l2 = l2->next;
            }

            lastNode = lastNode->next;
        }

        lastNode->next = (l1 != NULL) ? l1 : l2;
        return dummy->next;
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
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);
    l1->next->next->next = new ListNode(7);
    l1->next->next->next->next = new ListNode(9);

    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);
    l2->next->next->next = new ListNode(8);
    l2->next->next->next->next = new ListNode(10);

    ListNode* merged = Solution().mergeTwoLists(l1, l2);
    
    printList(merged);

    return 0;
}