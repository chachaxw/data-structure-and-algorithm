/**
 * @Author: Chacha 
 * @Date: 2018-12-30 17:45:36 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-12-30 19:04:14
 */

#include<iostream>
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
     * Given a sorted linked list, delete all duplicates such that each element appear only once.
     * Example 1:
     *  Input: 1->1->2
     *  Output: 1->2
     * 
     * Example 2:
     *  Input: 1->1->2->3->3
     *  Output: 1->2->3
     * 
     * Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list/solution/
     */ 
    ListNode* deleteDuplicates1(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *current = head;
        while(current->next != NULL) {
            if (current->val == current->next->val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return head;
    }

    /**
     * Given a sorted linked list, delete all nodes that have duplicate numbers, 
     * leaving only distinct numbers from the original list.
     * Example 1:
     *  Input: 1->2->3->3->4->4->5
     *  Output: 1->2->5
     * 
     * Example 2:
     *  Input: 1->1->1->2->3
     *  Output: 2->3
     * 
     * Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
     *         https://www.kancloud.cn/kancloud/data-structure-and-algorithm-notes/73003
     */ 
    ListNode* deleteDuplicates2(ListNode* head) {
        
        if (head == NULL) {
            return NULL;
        }

        // Add a dummy node to the linked list
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode* node = dummy;

        while(node->next != NULL && node->next->next != NULL) {
            if (node->next->val == node->next->next->val) {
                int prevVal = node->next->val;
                // remove ListNode node->next
                while (node->next != NULL && prevVal == node->next->val) {
                    ListNode* temp = node->next;
                    node->next = node->next->next;
                    delete temp;
                }
            } else {
                node = node->next;
            }
        }
        
        return dummy->next;
    }

};

int main() {
    return 0;
}