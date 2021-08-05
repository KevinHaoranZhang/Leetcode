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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode*> level_queue;
        level_queue.push(root);
        int level_cnt = 0;
        while (!level_queue.empty()) {
            ++level_cnt;
            int node_cnt = level_queue.size();
            vector<int> level;
            for (int i = 0; i < node_cnt; ++i) {
                TreeNode* node = level_queue.front();
                if (node->left != NULL) {
                    level_queue.push(node->left);
                }
                if (node->right != NULL) {
                    level_queue.push(node->right);
                }
                if (level_cnt % 2 != 0) {
                    level.push_back(node->val);
                } else {
                    level.insert(level.begin(), node->val);
                } 
                level_queue.pop();
            }
            ans.push_back(level);
        }
        return ans;
    }
};
