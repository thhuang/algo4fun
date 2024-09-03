"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""


class Solution:

    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        root = p
        while root.parent is not None:
            root = root.parent

        p_path, q_path = None, None

        path = []

        def dfs(u: 'Node'):
            nonlocal path
            nonlocal p_path
            nonlocal q_path

            if u is None:
                return

            path.append(u)

            if u == p:
                p_path = path.copy()
            if u == q:
                q_path = path.copy()

            dfs(u.left)
            dfs(u.right)

            path.pop()

        dfs(root)

        n = min(len(p_path), len(q_path))
        for i in range(n):
            if p_path[i] != q_path[i]:
                return p_path[i - 1]

        return p_path[n - 1]
