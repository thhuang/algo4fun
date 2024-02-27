# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        result = 0

        def dfs(u):
            nonlocal result

            if u is None:
                return 0

            l = dfs(u.left)
            r = dfs(u.right)

            result = max(result, l + r)

            return 1 + max(l, r)

        dfs(root)

        return result
