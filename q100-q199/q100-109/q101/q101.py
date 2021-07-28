# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root == None:
            return True
        return self.isSymmetric_helper(root.left, root.right)
        
    def isSymmetric_helper(self, left: TreeNode, right: TreeNode) -> bool:
        if left == None and right == None:
            return True
        if left == None or right == None:
            return False
        if left.val != right.val:
            return False
        return self.isSymmetric_helper(left.left, right.right) and \
        self.isSymmetric_helper(left.right, right.left)
