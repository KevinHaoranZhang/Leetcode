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
#include <queue>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<std::pair<int, ListNode*>, vector<std::pair<int, ListNode*>>, greater<std::pair<int, ListNode*>>> pq;
        ListNode* head = new ListNode(0);
        ListNode* cur_node = head;
        for (int i = 0; i < lists.size(); i++){
            if(lists[i] != NULL)
                pq.push(std::make_pair(lists[i]->val, lists[i]));
        }
        while (!pq.empty()){
            ListNode* node = pq.top().second;
            cur_node->next = new ListNode(node->val);
            pq.pop();
            cur_node = cur_node->next;
            node = node->next;
            if (node != NULL)
                pq.push(std::make_pair(node->val, node));
            
        }
        return head->next;
    }
};
