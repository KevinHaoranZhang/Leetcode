# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    prev = None
    first = None
    second = None
    
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def inorder(root):
            if root != None:
                inorder(root.left)
                if self.prev and root.val < self.prev.val:
                    if not self.first:
                        self.first = self.prev
                    self.second = root
                self.prev = root
                inorder(root.right)
        inorder(root)
        self.first.val, self.second.val = self.second.val, self.first.val
