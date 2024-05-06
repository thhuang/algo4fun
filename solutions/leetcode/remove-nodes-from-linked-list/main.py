# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def reverse(self, head):
        a = None
        b = head
        while b is not None:
            c = b.next
            b.next = a
            a, b = b, c
        return a

    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        head = self.reverse(head)
        p = head
        while p.next is not None:
            if p.val > p.next.val:
                p.next = p.next.next
            else:
                p = p.next
        return self.reverse(head)
