# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head == None or k == 0:
            return head
        size = 1
        tail = head
        while tail.next != None:
            size += 1
            tail = tail.next
        tail.next = head
        for i in range(size - k%size):
            head = head.next
            tail = tail.next
        tail.next = None
        return head
