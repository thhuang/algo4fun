# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def length(self, head: Optional[ListNode]) -> int:
        result = 0

        u = head
        while u is not None:
            result += 1
            u = u.next

        return result

    def reversed(self, head: Optional[ListNode]) -> Optional[ListNode]:
        a = None
        b = head
        while b is not None:
            c = b.next
            b.next = a
            a, b = b, c

        return a

    def pairSum(self, head: Optional[ListNode]) -> int:
        n = self.length(head)

        p = head
        for _ in range(n // 2):
            p = p.next

        r = self.reversed(p)
        l = head

        result = 0
        while l is not None and r is not None:
            result = max(result, l.val + r.val)
            l = l.next
            r = r.next

        return result
