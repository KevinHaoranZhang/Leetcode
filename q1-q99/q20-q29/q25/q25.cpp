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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur_node = head;
        ListNode* first = head;
        ListNode* second = head->next;
        
        if (checkavail(cur_node, k)){
            for (int i = 0; i < k-1; i++){
                first->next = second->next;
                second->next = head;
                head = second;
                second = first->next;
            }
        }
        ListNode* pre_tail = first;
        cur_node = second;
        while (checkavail(cur_node, k)){
            first = cur_node;
            second = first->next;
            for (int i = 0; i < k-1; i++){
                first->next = second->next;
                second->next = cur_node;
                cur_node = second;
                second = first->next;
            }
            pre_tail->next = cur_node;
            pre_tail = first;
            cur_node = first->next;
        }
        
        return head;
            
    }
    bool checkavail(ListNode* head, int k){
        int count = 0;
        if (head == NULL)
            return false;
        for(int i = 0; i < k; i++){
            if(head != NULL){
                head = head->next;
                count++;
            }
        }
        if (count == k)
            return true;
        return false;
    }
    
};
