# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import queue

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []
        level_que = queue.SimpleQueue()
        ans = []
        level_que.put(root)
        while not level_que.empty():
            cur_level_cnt = level_que.qsize()
            cur_level = []
            for i in range(0, cur_level_cnt):
                node = level_que.get()
                if node.left != None:
                    level_que.put(node.left)
                if node.right != None:
                    level_que.put(node.right)
                cur_level.append(node.val)
            ans.append(cur_level)
        return ans

