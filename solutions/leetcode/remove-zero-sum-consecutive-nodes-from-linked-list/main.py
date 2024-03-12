# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head)

        prefix = defaultdict(lambda: [])
        s = 0
        p = dummy
        while p is not None:
            s += p.val
            prefix[s].append(p)
            p = p.next

        for k, v in prefix.items():
            if len(v) <= 1:
                continue
            v[0].next = v[-1].next
            self.removeZeroSumSublists(dummy.next)
            break

        return dummy.next
