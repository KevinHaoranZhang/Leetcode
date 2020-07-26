# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dum_head = ListNode();
        dum_head.next = head;
        fast = dum_head;
        slow = dum_head;
        for i in range(n):
            fast = fast.next;
        while fast.next != None:
            fast = fast.next;
            slow = slow.next;
        slow.next = slow.next.next;
        return dum_head.next;
