import heapq


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def mergeKLists(self,
                    lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        ListNode.__lt__ = lambda self, other: self.val < other.val

        dummy = ListNode()
        p = dummy

        q = []
        for u in lists:
            if u is not None:
                heapq.heappush(q, u)

        while len(q) > 0:
            u = heapq.heappop(q)
            p.next = u
            p = p.next
            if u.next is not None:
                heapq.heappush(q, u.next)

        return dummy.next
