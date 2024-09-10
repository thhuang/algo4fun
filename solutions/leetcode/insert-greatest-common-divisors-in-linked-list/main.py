# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        a = head
        b = head.next
        while b is not None:
            a.next = ListNode(gcd(a.val, b.val), b)
            a = b
            b = b.next
        return head
