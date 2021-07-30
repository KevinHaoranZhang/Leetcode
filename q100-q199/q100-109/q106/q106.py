# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        def buildTree_helper(left: int, right: int):
            nonlocal postorder_index
            if left > right:
                return None
            node_val = postorder[postorder_index]
            node = TreeNode(node_val)
            postorder_index -= 1
            node.right = buildTree_helper(inorder_hash[node_val] + 1, right)
            node.left = buildTree_helper(left, inorder_hash[node_val] - 1)
            return node
        inorder_hash = {}
        postorder_index = len(inorder) - 1
        for index, value in enumerate(inorder):
            inorder_hash[value] = index
        return buildTree_helper(0, len(inorder) - 1)
