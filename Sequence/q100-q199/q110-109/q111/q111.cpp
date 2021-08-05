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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode*> level_que;
        int min_depth = 0;
        level_que.push(root);
        while (!level_que.empty()) {
            int level_size = level_que.size();
            ++min_depth;
            for (int i = 0; i < level_size; ++i) {
                TreeNode* node = level_que.front();
                level_que.pop();
                if (node->left == NULL && node->right == NULL) {
                    return min_depth;
                }
                if (node->left != NULL) {
                    level_que.push(node->left);
                }
                if (node->right != NULL) {
                    level_que.push(node->right);
                }
            }
        }
        return min_depth;
    }
};
