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
    vector<TreeNode*> generateTrees(int n) {
        if (n==0) {
            return {};
        }
        return generateTrees_helper(1, n);
    }
    vector<TreeNode*> generateTrees_helper(int start, int end) {
        if (start > end) {
            return {nullptr};
        }
        vector<TreeNode*> all_trees;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left_trees = generateTrees_helper(start, i - 1);
            vector<TreeNode*> right_trees = generateTrees_helper(i + 1, end);
            for (auto left_tree : left_trees) {
                for (auto right_tree: right_trees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left_tree;
                    root->right = right_tree;
                    all_trees.emplace_back(root);
                }
            }
        }
        return all_trees;
    }
};
