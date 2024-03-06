# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:

    def hasCycle(self, head: Optional[ListNode]) -> bool:
        dummy = ListNode(0)
        dummy.next = head
        slow, fast = dummy, head
        while fast is not None and fast.next is not None and slow != fast:
            slow = slow.next
            fast = fast.next.next
        return fast is not None and fast.next is not None
