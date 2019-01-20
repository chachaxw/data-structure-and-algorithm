/**
 * @Author: Chacha 
 * @Date: 2019-01-18 16:38:09 
 * @Last Modified by: Chacha
 * @Last Modified time: 2019-01-18 18:50:29
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
     * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
     * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
     * 
     * Note: You must do this in-place without altering the nodes' values.
     * 
     * Example: 
     *  Given 1->2->3->4->null, reorder it to 1->4->2->3->null.
     * 
     * Source: https://www.kancloud.cn/kancloud/data-structure-and-algorithm-notes/73015
     */
    void reorderList1(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return;
        }

        ListNode* last = head;
        int length = 0;
        while(last != NULL) {
            last = last->next;
            ++length;
        }

        last = head;

        for(int i = 1; i < length - i; ++i) {
            ListNode* beforeTail = last;
            
            for(int j = i; j < length - i; ++j) {
                beforeTail = beforeTail->next;
            }

            ListNode* temp = last->next;
            last->next = beforeTail->next;
            last->next->next = temp;
            beforeTail->next = NULL;
            last = temp;
        }
    }

    void reorderList2(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next) return;

        ListNode* middle = findMiddle(head);
        ListNode* right = reverse(middle->next);
        middle->next = NULL;

        merge(head, right);
    }

    void merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0);

        while(left != NULL && right != NULL){
            dummy->next = left;
            left = left->next;
            dummy = dummy->next;
            dummy->next = right;
            right = right->next;
            dummy = dummy->next;
        }

        dummy->next = left != NULL ? left : right;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* newHead = NULL;
        
        while(head != NULL){
            ListNode* temp = head->next;
            head->next = newHead;
            newHead = head;
            head = temp;
        }

        return newHead;
    }

    ListNode* findMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *slow = head, *fast = head->next;
        while (slow != NULL && fast != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
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
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    Solution().reorderList2(head);
    printList(head);

    return 0;
}