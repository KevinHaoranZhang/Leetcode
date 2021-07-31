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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST_helper(nums, 0, nums.size() - 1);
    }
    
    TreeNode* sortedArrayToBST_helper(vector<int>& nums, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int middle = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[middle]);
        node->left = sortedArrayToBST_helper(nums, left, middle - 1);
        node->right = sortedArrayToBST_helper(nums, middle + 1, right);
        return node;
    }
};
