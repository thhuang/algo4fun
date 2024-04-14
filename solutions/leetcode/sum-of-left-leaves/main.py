# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        result = 0

        def dfs(u):
            nonlocal result

            if u is None:
                return 0
            if u.left is None and u.right is None:
                return u.val

            l = dfs(u.left)
            dfs(u.right)

            result += l

            return 0

        dfs(root)

        return result
