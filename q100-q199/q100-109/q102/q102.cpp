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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> level_que;
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        level_que.push(root);
        while (!level_que.empty()) {
            int cur_level_cnt = level_que.size();
            vector<int> cur_level;
            for (int i = 0; i < cur_level_cnt; ++i) {
                TreeNode* node = level_que.front();
                if (node->left != NULL) {
                    level_que.push(node->left);
                }
                if (node->right != NULL) {
                    level_que.push(node->right);
                }
                cur_level.push_back(node->val);
                level_que.pop();
            }
            ans.push_back(cur_level);
        }
        return ans;
    }
};
