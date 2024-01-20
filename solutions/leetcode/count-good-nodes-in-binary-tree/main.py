# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def goodNodes(self, root: TreeNode) -> int:

        def dfs(u: TreeNode, mx: int) -> int:
            if u is None:
                return 0
            mx = max(mx, u.val)
            result = 1 if u.val >= mx else 0
            result += dfs(u.left, mx)
            result += dfs(u.right, mx)
            return result

        return dfs(root, -inf)
