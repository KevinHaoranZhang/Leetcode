# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import queue
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []
        ans = []
        level_cnt = 0
        level_queue = queue.SimpleQueue()
        level_queue.put(root)
        while not level_queue.empty():
            level_cnt += 1
            node_size = level_queue.qsize()
            level = []
            for i in range(0, node_size):
                node = level_queue.get()
                if node.left != None:
                    level_queue.put(node.left)
                if node.right != None:
                    level_queue.put(node.right)
                if level_cnt % 2 != 0:
                    level.append(node.val)
                else:
                    level.insert(0, node.val)
            ans.append(level)
        return ans
