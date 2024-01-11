# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:

        result = 0

        def dfs(u: TreeNode) -> Tuple[int]:
            nonlocal result

            if not u:
                return (inf, -inf)

            l_mn, l_mx = dfs(u.left)
            r_mn, r_mx = dfs(u.right)

            mn = min(l_mn, r_mn)
            mx = max(l_mx, r_mx)

            result = max((result, mx - u.val, u.val - mn))

            return (min(mn, u.val), max(mx, u.val))

        dfs(root)

        return result
