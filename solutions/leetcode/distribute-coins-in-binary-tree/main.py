# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        result = 0

        def dfs(u):
            nonlocal result

            if u is None:
                return 0

            l = dfs(u.left)
            r = dfs(u.right)

            result += abs(l) + abs(r)

            return u.val - 1 + l + r

        dfs(root)

        return result
