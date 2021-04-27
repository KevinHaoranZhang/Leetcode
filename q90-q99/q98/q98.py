# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def helper(node, lower = float('-inf'), upper = float('inf')) -> bool:
            if not node:
                return True
            val = node.val
            if val <= lower or val >= upper:
                return False
            return (helper(node.left, lower, val) and helper(node.right, val, upper))

        return helper(root)
