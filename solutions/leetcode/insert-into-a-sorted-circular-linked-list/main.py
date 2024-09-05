"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next
"""


class Solution:

    def insert(self, head: 'Optional[Node]', insert_val: int) -> 'Node':
        if head is None:
            u = Node(insert_val)
            u.next = u
            return u

        p = head
        while True:
            between = p.val <= insert_val <= p.next.val
            begin = p.val > p.next.val and insert_val <= p.next.val
            end = p.val > p.next.val and p.val <= insert_val
            mono = p.next == head
            if between or begin or end or mono:
                u = Node(insert_val, p.next)
                p.next = u
                break
            p = p.next

        return head
