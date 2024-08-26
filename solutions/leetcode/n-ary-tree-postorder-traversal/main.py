"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:

    def postorder(self, root: 'Node') -> List[int]:
        result = []

        def search(u):
            nonlocal result
            if u is None:
                return
            for v in u.children:
                search(v)
            result.append(u.val)

        search(root)

        return result
