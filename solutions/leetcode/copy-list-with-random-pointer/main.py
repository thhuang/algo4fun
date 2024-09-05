"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""


class Solution:

    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        mp = {}

        def copy(u: 'Optional[Node]') -> 'Optional[Node]':
            if u is None:
                return None

            if u in mp:
                return mp[u]

            mp[u] = Node(u.val)
            mp[u].next = copy(u.next)
            mp[u].random = copy(u.random)

            return mp[u]

        return copy(head)
