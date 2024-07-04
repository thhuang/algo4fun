# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.next is None:
            return None

        v = 0
        p = head.next
        while p.val != 0:
            v += p.val
            p = p.next

        return ListNode(v, self.mergeNodes(p))
