/**
 * @Author: Chacha 
 * @Date: 2018-12-31 23:03:47 
 * @Last Modified by: Chacha
 * @Last Modified time: 2019-01-01 20:58:16
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
     * Reverse a linked list.
     * duplicate nodes from the list. The list is not sorted.
     * 
     * Example: 
     *  For linked list 1->2->3, the reversed linked list is 3->2->1
     * 
     * Source: https://www.kancloud.cn/kancloud/data-structure-and-algorithm-notes/73011
     *         https://leetcode.com/problems/reverse-linked-list/solution/
     * 
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

    /**
     * Reverse a linked list from position m to n.
     * 
     * Example:
     *  Given 1->2->3->4->5->NULL, m = 2 and n = 4, return1->4->3->2->5->NULL.
     * 
     * Note:
     *  Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.
     * 
     * Source: https://leetcode.com/problems/reverse-linked-list-ii/
     *         https://www.kancloud.cn/kancloud/data-structure-and-algorithm-notes/73012
     * 
     * Operation steps:
     *  1. Since only the specified area is flipped, the affected area is analyzed as the m-1th and n+1th nodes.
     *  2. Find the mth node, use the for loop n-m times, use the linked list flip method in the previous question.
     *  3. Processing the m-1th and n+1th nodes.
     *  4. Return dummy->next
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || m > n) return NULL;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* node = dummy;
        
        for(int i = 1; i != m; i++) {
            if (node == NULL) {
                return NULL;
            } else {
                node = node->next;
            }
        }

        ListNode* preMNode = node;
        ListNode* mNode = preMNode->next;
        ListNode* nNode = mNode, *postNNode = nNode->next;
        
        for(int i = m; i != n; i++) {
            if (postNNode == NULL) return NULL;
            
            ListNode* temp = postNNode->next;
            postNNode->next = nNode;
            nNode = postNNode;
            postNNode = temp;
        }
        preMNode->next = nNode;
        mNode->next = postNNode;

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
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* reversed = Solution().reverseBetween(head, 2, 4);
    
    printList(reversed);

    return 0;
}