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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST_helper(head, NULL);
    }
    
    TreeNode* sortedListToBST_helper(ListNode* left, ListNode* right) {
        if (left == right) {
            return NULL;
        }
        // find the middle of linked list, using fast & slow pointer
        ListNode* fast = left;
        ListNode* slow = left;
        while (fast != right && fast->next != right) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // here slow is the middle of linked list
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST_helper(left, slow);
        root->right = sortedListToBST_helper(slow->next, right);
        return root;
    }
};
