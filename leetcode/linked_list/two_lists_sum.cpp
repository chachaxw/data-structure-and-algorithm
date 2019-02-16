/**
 * @Author: Chacha 
 * @Date: 2019-02-14 10:00:00 
 * @Last Modified by: Chacha
 * @Last Modified time: 2019-02-14 10:17:20
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
     * You have two numbers represented by a linked list, where each node contains a single digit.
     * The digits are stored in reverse order, such that the 1’s digit is at the head of the list.
     * Write a function that adds the two numbers and returns the sum as a linked list.
     *
     * Example:
     *  Given two lists, 3->1->5->null and 5->9->2->null, return 8->0->8->null
     * 
     * Source:
     *  https://www.lintcode.com/en/problem/two-lists-sum/
     *  https://www.kancloud.cn/kancloud/data-structure-and-algorithm-notes/73006
     */
    ListNode* twoListsSum1(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }

        ListNode* sumList = new ListNode(0);
        ListNode* tempList = sumList;

        int carry = 0;
        while((l1 != NULL) || (l2 != NULL) || (carry != 0)){
            int l1_val = (l1 == NULL) ? 0 : l1->val;
            int l2_val = (l2 == NULL) ? 0 : l2->val;

            tempList->val = (carry + l1_val + l2_val) % 10;
            carry = (carry + l1_val + l2_val) / 10;

            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;

            // return sumlist before generating new ListNode
            if ((l1 == NULL) && (l2 == NULL) && (carry == 0)) {
                return sumList;
            }
            
            tempList->next = new ListNode(0);
            tempList = tempList->next;
        }
        
        return sumList;
    }

    /**
     * Given two numbers represented by two linked lists, write a function that returns sum list.
     * The sum list is linked list representation of addition of two input numbers.
     * 
     * Example:
     *  Input:
     *      First  List: 5->6->3  // represents number 563
     *      Second List: 8->4->2  // represents number 842
     *  Output:
     *      Resultant list: 1->4->0->5  // represents number 1405
     */
    ListNode* twoListsSum2(ListNode* l1, ListNode* l2) {
        
    }
};

/* Function to print nodes in a given linked list */
void printList(ListNode *node) { 
    while (node != NULL) { 
        printf("%d ", node->val);
        node = node->next; 
    }
}

int main()
{
    ListNode* l1 = new ListNode(3);
    l1->next = new ListNode(1);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(2);

    ListNode* sum = Solution().twoListsSum1(l1, l2);

    printList(sum);

    return 0;
}
