# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:
        def back_track(cur_node: TreeNode, targetSum: int, cur_path: List[int]):
            nonlocal ans
            if cur_node.left == None and cur_node.right == None:
                if cur_node.val == targetSum:
                    cur_path.append(cur_node.val)
                    ans.append(copy.deepcopy(cur_path))
                    cur_path.pop()
                return
            cur_path.append(cur_node.val)
            if cur_node.left != None:
                back_track(cur_node.left, targetSum - cur_node.val, cur_path)
            if cur_node.right != None:
                back_track(cur_node.right, targetSum - cur_node.val, cur_path)
            cur_path.pop()
        
        if root == None:
            return []
        
        ans = []
        back_track(root, targetSum, [])
        return ans
