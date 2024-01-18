# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        odd = ListNode(0, head)
        even = ListNode(0, head)
        odd_prev = odd
        even_prev = even

        is_odd = True
        while head is not None:
            if is_odd:
                odd.next = head
                odd = odd.next
            else:
                even.next = head
                even = even.next
            head = head.next
            is_odd = not is_odd

        even.next = None
        odd.next = even_prev.next

        return odd_prev.next
