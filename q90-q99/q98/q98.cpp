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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> node_stack;
        TreeNode* cur = root;
        long long prev_value = (long long)INT_MIN - 1;
        while (cur != NULL || !node_stack.empty()) {
            while (cur != NULL) {
                node_stack.push(cur);
                cur = cur->left;
            }
            cur = node_stack.top();
            node_stack.pop();
            if (prev_value >= cur->val) {
                return false;
            }
            prev_value = cur->val;
            cur = cur->right;
        }
        return true;
    }
};
