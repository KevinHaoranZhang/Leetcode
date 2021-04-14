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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        vector<int> inorder_nodes;
        stack<TreeNode*> node_stack;
        while (cur != NULL || !node_stack.empty()) {
            while (cur != NULL) {
                node_stack.push(cur);
                cur = cur->left;
            }
            cur = node_stack.top();
            node_stack.pop();
            inorder_nodes.push_back(cur->val);
            cur = cur->right;
        }
        return inorder_nodes;
    }
};
