# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        inorder_nodes = []
        node_stack = []
        cur = root
        while cur != None or len(node_stack) != 0:
            while cur != None:
                node_stack.append(cur)
                cur = cur.left
            cur = node_stack.pop()
            inorder_nodes.append(cur.val)
            cur = cur.right
        return inorder_nodes
