# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        result = 0

        def dfs(u: Optional[TreeNode]) -> int:
            nonlocal result

            if u is None:
                return 0

            l = dfs(u.left)
            r = dfs(u.right)

            if u.val == start:
                result = max(l, r)
                return -1
            if l >= 0 and r >= 0:
                return max(l, r) + 1
            if l < 0:
                result = max(result, r - l)
                return l - 1
            if r < 0:
                result = max(result, l - r)
                return r - 1

            return None

        dfs(root)

        return result
