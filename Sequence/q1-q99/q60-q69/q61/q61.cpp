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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == NULL)
            return head;
        int len = 1;
        ListNode* tail = head;
        while (tail->next != NULL){
            len++;
            tail = tail->next;
        }
        tail->next = head;
        for (int i = 0; i < len - k%len; i++){
            head = head->next;
            tail = tail->next;
        }
        tail->next = NULL;
        return head;
    }
};
