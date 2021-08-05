/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;
        ListNode* solution = new ListNode(0);
        solution->next = head;
        ListNode* first = head;
        ListNode* second = head->next;
        first->next = second->next;
        second->next = first;
        solution->next = second;
        ListNode* cur_node = first;
        while (first->next != NULL && first->next->next != NULL){
            first = first->next;
            second = first->next;
            first->next = second->next;
            second->next = first;
            cur_node->next = second;
            cur_node = first;
        }
        return solution->next;
    }
};
