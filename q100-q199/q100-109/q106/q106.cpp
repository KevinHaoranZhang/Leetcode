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
    int postorder_index = 0;
    unordered_map<int, int> inorder_hash;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_hash.emplace(inorder[i], i);
        }
        postorder_index = postorder.size() - 1;
        return buildTree_helper(postorder, 0, postorder.size() - 1);
    }
    
    TreeNode* buildTree_helper(vector<int>& postorder, int left, int right) {
        if (left > right) {
            return NULL;
        }
        
        TreeNode* node = new TreeNode(postorder[postorder_index--]);
        node->right = buildTree_helper(postorder, inorder_hash[node->val] + 1, right);
        node->left = buildTree_helper(postorder, left, inorder_hash[node->val] - 1);
        return node;
    }
};
