# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        isDuplicate = False
        if head == None:
            return head;
        while head.next and head.val == head.next.val:
            head = head.next
            isDuplicate = True
        if isDuplicate:
            head = self.deleteDuplicates(head.next)
        else:
            head.next = self.deleteDuplicates(head.next)
        return head;
