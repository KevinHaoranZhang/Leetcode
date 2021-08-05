# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        def sortedListToBST_helper(left: ListNode, right: ListNode) -> TreeNode:
            if left == right:
                return None
            fast, slow = left, left
            while fast != right and fast.next != right:
                fast = fast.next.next
                slow = slow.next
            root = TreeNode(slow.val)
            root.left = sortedListToBST_helper(left, slow)
            root.right = sortedListToBST_helper(slow.next, right)
            return root
        return sortedListToBST_helper(head, None)
