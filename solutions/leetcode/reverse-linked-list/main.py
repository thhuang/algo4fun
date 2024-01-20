# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        a = None
        b = head
        while b is not None:
            c = b.next
            b.next = a
            a, b = b, c
        return a
