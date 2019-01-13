/**
 * @Author: Chacha 
 * @Date: 2019-01-12 17:12:07 
 * @Last Modified by: Chacha
 * @Last Modified time: 2019-01-13 09:42:39
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
     *         https://www.kancloud.cn/kancloud/data-structure-and-algorithm-notes/73017
     * 
     */ 
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* slow = head;
        ListNode* fast= head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // divide the list into two parts 
        fast = slow->next;
        slow->next = NULL;
        
        return merge(sortList(head), sortList(fast));
    }

    // Merge sort
    ListNode* merge(ListNode* l1, ListNode* l2) {
        
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while(l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }

            curr = curr->next;
        }
        
        curr->next = (l1 != NULL) ? l1 : l2;

        return dummy.next;
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