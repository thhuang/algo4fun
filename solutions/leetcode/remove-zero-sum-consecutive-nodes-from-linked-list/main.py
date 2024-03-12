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

        for v in prefix.values():
            if len(v) <= 1:
                continue
            v[0].next = v[-1].next
            self.removeZeroSumSublists(dummy.next)
            break

        return dummy.next


class Solution:

    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head)

        prefix_sum_to_node = dict()
        prefix_sum = 0

        p = dummy

        while p is not None:
            prefix_sum += p.val

            if prefix_sum not in prefix_sum_to_node:
                prefix_sum_to_node[prefix_sum] = p

            else:
                l = prefix_sum_to_node[prefix_sum]

                r = l.next
                v = prefix_sum + r.val
                while r != p:
                    del prefix_sum_to_node[v]
                    r = r.next
                    v += r.val

                l.next = r.next

            p = p.next

        return dummy.next
