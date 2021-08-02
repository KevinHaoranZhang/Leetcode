# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import queue
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        level_que = queue.SimpleQueue()
        level_que.put(root)
        min_depth = 0
        while not level_que.empty():
            level_size = level_que.qsize()
            min_depth += 1
            for i in range(0, level_size):
                node = level_que.get()
                if node.left == None and node.right == None:
                    return min_depth
                if node.left != None:
                    level_que.put(node.left)
                if node.right != None:
                    level_que.put(node.right)
        return min_depth
