# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        def checkavail(head, k):
            if head == None:
                return False
            count = 0;
            for i in range(k):
                if(head != None):
                    count += 1
                    head = head.next
            if count == k:
                return True
            return False
        if not checkavail(head, k):
            return head
        cur_node = head
        first = head
        second = first.next
        for i in range(k-1):
            first.next = second.next
            second.next = head
            head = second
            second = first.next
        prev_tail = first
        cur_node = second
        while checkavail(cur_node, k):
            first = cur_node
            second = first.next
            for i in range(k-1):
                first.next = second.next
                second.next = cur_node
                cur_node = second
                second = first.next
            prev_tail.next = cur_node
            prev_tail = first
            cur_node = first.next
        return head
        
