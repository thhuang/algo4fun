# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def equalToDescendants(self, root: Optional[TreeNode]) -> int:
        result = 0

        def dfs(u):
            nonlocal result

            if u is None:
                return 0

            l, r = dfs(u.left), dfs(u.right)

            if u.val == l + r:
                result += 1

            return u.val + l + r

        dfs(root)

        return result
