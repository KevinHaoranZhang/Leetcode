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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode start(0);
      ListNode *start_next = &start;
      
      int transfer = 0;
      while(l1 || l2 || transfer) {
    
        int res = (l1? l1->val : 0) + (l2 ? l2->val : 0) + transfer;
        transfer = res / 10;
        
        start_next->next = new ListNode(res % 10);
        start_next = start_next->next;

        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
      }
        
      return start.next;
    }
};
