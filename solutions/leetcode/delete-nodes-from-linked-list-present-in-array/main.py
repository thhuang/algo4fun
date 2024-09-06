# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        target = set(nums)

        dummy = ListNode(next=head)
        p = dummy

        while p.next is not None:
            if p.next.val in target:
                p.next = p.next.next
            else:
                p = p.next

        return dummy.next
