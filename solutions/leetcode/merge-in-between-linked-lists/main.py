# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        p = list1
        for _ in range(a - 1):
            p = p.next

        q = list1
        for _ in range(b + 1):
            q = q.next

        r = list2
        while r.next is not None:
            r = r.next

        p.next = list2
        r.next = q

        return list1
