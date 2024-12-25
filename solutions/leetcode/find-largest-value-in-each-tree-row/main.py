# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []

        result = []
        q = deque([root])

        while len(q) > 0:
            mx = -float("inf")
            n = len(q)
            for _ in range(n):
                u = q.popleft()
                mx = max(mx, u.val)
                if u.left is not None:
                    q.append(u.left)
                if u.right is not None:
                    q.append(u.right)
            result.append(mx)

        return result
