# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def length(self, u):
        result = 0
        while u is not None:
            result += 1
            u = u.next
        return result

    def reverse(self, head):
        a, b = None, head
        while b is not None:
            c = b.next
            b.next = a
            a, b = b, c
        return a

    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """

        n = self.length(head)
        p = head
        for _ in range((n - 1) // 2):
            p = p.next

        a = head
        b = self.reverse(p.next)
        p.next = None

        result = a
        p = a
        a = a.next

        for i in range(n - 1):
            if i % 2 == 0:
                p.next = b
                b = b.next
            else:
                p.next = a
                a = a.next
            p = p.next

        return result
