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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode*> level_que;
        level_que.push(root);
        while (!level_que.empty()) {
            int level_size = level_que.size();
            vector<int> level;
            for (int i = 0; i < level_size; ++i) {
                TreeNode* node = level_que.front();
                level_que.pop();
                level.push_back(node->val);
                if (node->left != NULL) {
                    level_que.push(node->left);
                }
                if (node->right != NULL) {
                    level_que.push(node->right);
                }
            }
            ans.push_back(level);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
