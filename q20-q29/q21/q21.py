# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode()
        cur_node = head
        while l1:
            if l2 != None:
                if l1.val < l2.val:
                    new_node = ListNode(l1.val)
                    cur_node.next = new_node
                    cur_node = cur_node.next
                    l1 = l1.next
                else:
                    new_node = ListNode(l2.val)
                    cur_node.next = new_node
                    cur_node = cur_node.next
                    l2 = l2.next
            else:
                while l1:
                    new_node = ListNode(l1.val)
                    cur_node.next = new_node
                    cur_node = cur_node.next
                    l1 = l1.next
        while l2:
            new_node = ListNode(l2.val)
            cur_node.next = new_node
            cur_node = cur_node.next
            l2 = l2.next
        return head.next
