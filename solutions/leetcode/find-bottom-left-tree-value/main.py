# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        result = None

        q = deque([root])

        while len(q) > 0:
            n = len(q)

            for _ in range(n):
                u = q.popleft()
                result = u.val

                if u.right is not None:
                    q.append(u.right)
                if u.left is not None:
                    q.append(u.left)

        return result
