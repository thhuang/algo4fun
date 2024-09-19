"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""


class Solution:

    def treeToDoublyList(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if root is None:
            return None

        sorted_node = []

        stack = [(root, False)]
        while len(stack) > 0:
            u, visited = stack.pop()

            if visited:
                sorted_node.append(u)
                continue

            if u.right is not None:
                stack.append((u.right, False))

            stack.append((u, True))

            if u.left is not None:
                stack.append((u.left, False))

        n = len(sorted_node)

        for i in range(n):
            sorted_node[i].right = sorted_node[(i + 1) % n]
            sorted_node[i].left = sorted_node[i - 1]

        return sorted_node[0]
