# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        mn = inf
        mx = 0

        l, il, ill = None, -1, -1
        r, ir = head, 0
        while r.next is not None and r.next.next is not None:
            if r.val < r.next.val > r.next.next.val or r.val > r.next.val < r.next.next.val:
                if l is not None:
                    mn = min(mn, ir - il + 1)
                else:
                    ill = ir + 1
                mx = max(mx, ir - ill + 1)
                l, il = r.next, ir + 1
            r, ir = r.next, ir + 1

        return [mn, mx] if mn <= mx else [-1, -1]
