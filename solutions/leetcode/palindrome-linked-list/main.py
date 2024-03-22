# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def isPalindrome(self, head: Optional[ListNode]) -> bool:

        def length(u):
            result = 0
            while u is not None:
                result += 1
                u = u.next
            return result

        def reverse(head):
            a = None
            b = head
            while b is not None:
                c = b.next
                b.next = a
                a = b
                b = c
            return a

        n = length(head)
        h = (n - 1) // 2

        m = head
        for _ in range(h):
            m = m.next

        r = reverse(m.next)
        m.next = None

        l = head

        while r is not None:
            if l.val != r.val:
                return False
            l, r = l.next, r.next

        return True
