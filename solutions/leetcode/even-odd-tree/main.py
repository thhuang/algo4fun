# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        q = deque([root])

        level = 0
        while len(q):
            n = len(q)

            is_even_level = level % 2 == 0

            p = -inf if is_even_level else inf

            for _ in range(n):
                u = q.popleft()

                if is_even_level:
                    if u.val % 2 == 0 or p >= u.val:
                        return False
                else:
                    if u.val % 2 == 1 or p <= u.val:
                        return False

                p = u.val

                if u.left is not None:
                    q.append(u.left)
                if u.right is not None:
                    q.append(u.right)

            level += 1

        return True
