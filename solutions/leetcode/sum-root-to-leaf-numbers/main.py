# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        result = 0

        def dfs(u, v):
            nonlocal result

            v += u.val

            if u.left is None and u.right is None:
                result += v
                return

            if u.left is not None:
                dfs(u.left, v * 10)
            if u.right is not None:
                dfs(u.right, v * 10)

        dfs(root, 0)

        return result
