# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:

        def length(head: Optional[ListNode]) -> int:
            result = 0
            p = ListNode(next=head)
            while p.next is not None:
                result += 1
                p = p.next
            return result

        n = length(head)
        q = n // k
        r = n % k

        b = head
        result = []

        for i in range(k):
            result.append(b)
            a = ListNode(next=b)

            m = q
            if i < r:
                m += 1

            for _ in range(m):
                a = a.next

            b = a.next
            a.next = None

        return result
