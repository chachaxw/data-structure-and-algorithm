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
     */
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return;
        }

        ListNode* last = head;
        int length = 0;
        while(last != NULL) {
            last = last->next;
            ++length;
        }
        
    }
};

int main() {
    return 0;
}