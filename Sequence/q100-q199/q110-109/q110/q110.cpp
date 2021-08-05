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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        bool balanced = true;
        height(root, & balanced);
        return balanced;
    }
    
    int height(TreeNode* root, bool* balanced) {
        if (root == NULL) {
            return 0;
        }
        int left_height = height(root->left, balanced);
        int right_height = height(root->right, balanced);
        if (abs(left_height - right_height) > 1) {
            *balanced = false;
            return 1;
        }
        return 1 + max(left_height, right_height);
    }
};
