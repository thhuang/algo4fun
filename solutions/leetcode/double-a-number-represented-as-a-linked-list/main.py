# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def reverse(self, head):
        a, b = None, head
        while b is not None:
            c = b.next
            b.next = a
            a, b = b, c
        return a

    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(next=self.reverse(head))

        carry = 0
        p = dummy

        while p.next is not None:
            p.next.val = p.next.val * 2 + carry
            carry = p.next.val // 10
            p.next.val %= 10
            p = p.next

        if carry > 0:
            p.next = ListNode(carry)
            p = p.next

        return self.reverse(dummy.next)
