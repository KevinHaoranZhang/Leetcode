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
    // key: inorder node val
    // value: inorder node index
    unordered_map<int, int> inorder_hash;
    int preorder_index = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        // build inorder hash map
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_hash.emplace(inorder[i], i);
        }
        
        return buildTree_helper(preorder, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTree_helper(vector<int>& preorder, int left, int right) {
        if (left > right) {
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[preorder_index++]);
        // build left subtree in inorder array
        node->left = buildTree_helper(preorder, left, inorder_hash.at(node->val) - 1);
        // build right subtree in inorder array
        node->right = buildTree_helper(preorder, inorder_hash.at(node->val) + 1, right);
        return node;
    }
};
