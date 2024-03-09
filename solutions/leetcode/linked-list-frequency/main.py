# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def frequenciesOfElements(self,
                              head: Optional[ListNode]) -> Optional[ListNode]:
        freq = defaultdict(int)

        p = head
        while p is not None:
            freq[p.val] += 1
            p = p.next

        dummy = ListNode()
        p = dummy
        for v in freq.values():
            p.next = ListNode(v)
            p = p.next

        return dummy.next
