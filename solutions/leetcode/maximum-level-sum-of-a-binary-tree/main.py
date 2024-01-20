# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque


class Solution:

    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        result = 0
        mx = -inf

        q = deque([root])
        i = 1
        while len(q) > 0:
            n = len(q)
            s = 0

            for _ in range(n):
                u = q.popleft()

                s += u.val
                if u.left:
                    q.append(u.left)
                if u.right:
                    q.append(u.right)

            if s > mx:
                result = i
                mx = s

            i += 1

        return result
