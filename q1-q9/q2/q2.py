# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        solution = ListNode(0)
        solution_next = solution
        while(l1 or l2 or carry ):
            carry, sum = divmod (( l1.val if l1 else 0) + (l2.val if l2 else 0) + carry, 10)
            
            solution_next.next = ListNode(sum)
            solution_next = solution_next.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        
        return solution.next
        
