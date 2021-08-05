# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import queue
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []
        ans = []
        level_que = queue.SimpleQueue()
        level_que.put(root)
        while not level_que.empty():
            level = []
            level_size = level_que.qsize()
            for i in range(0, level_size):
                node = level_que.get()
                if node.left != None:
                    level_que.put(node.left)
                if node.right != None:
                    level_que.put(node.right)
                level.append(node.val)
            ans.append(level)
        return ans[::-1]
