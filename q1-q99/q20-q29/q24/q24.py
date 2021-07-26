# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head == None:
            return None
        if head.next == None:
            return head
        solution = ListNode(0)
        solution.next = head
        first = head
        second = head.next
        first.next = second.next
        second.next = first
        solution.next = second
        cur_node = first
        while first.next != None and first.next.next != None:
            first = first.next
            second = first.next
            first.next = second.next
            second.next = first
            cur_node.next = second
            cur_node = first
        return solution.next
