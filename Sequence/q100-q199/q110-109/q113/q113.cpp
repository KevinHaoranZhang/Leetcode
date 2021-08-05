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
private:
    vector<vector<int>> ans;
    vector<int> cur_path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return {};
        }
        back_track(root, targetSum);
        return ans;
    }
    
    void back_track(TreeNode* cur_node, int targetSum) {
        if (cur_node->left == NULL && cur_node->right == NULL) {
            if (cur_node->val == targetSum) {
                cur_path.push_back(cur_node->val);
                ans.push_back(cur_path);
                cur_path.pop_back();
            }
            return;
        }
        cur_path.push_back(cur_node->val);
        if (cur_node->left != NULL) {
            back_track(cur_node->left, targetSum - cur_node->val);
        }
        if (cur_node->right != NULL) {
            back_track(cur_node->right, targetSum - cur_node->val);
        }
        cur_path.pop_back();
    }
};
