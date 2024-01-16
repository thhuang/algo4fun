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

    def reverseKGroup(self, head: Optional[ListNode],
                      k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)

        p = dummy
        u = head

        while u is not None:
            r = u

            length_less_than_k = False
            for _ in range(k - 1):
                if r.next is None:
                    length_less_than_k = True
                    break
                r = r.next

            if length_less_than_k:
                break

            q = r
            r = r.next
            q.next = None

            l = self.reverse(u)

            p.next, u.next = l, r
            p, u = u, r

        return dummy.next
