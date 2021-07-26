# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        dummyHead = ListNode(-1)
        dummyHead.next = head
        prev = dummyHead
        count = 1
        while count < left:
            count += 1
            prev = prev.next
        cur = prev.next
        while count < right:
            count += 1
            temp = cur.next
            cur.next = temp.next
            temp.next = prev.next
            prev.next = temp
        return dummyHead.next
