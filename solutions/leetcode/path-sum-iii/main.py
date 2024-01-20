# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        result = 0
        prefix = defaultdict(int)
        prefix[0] += 1
        s = 0

        def dfs(u):
            nonlocal s
            nonlocal result

            if u is None:
                return

            s += u.val
            result += prefix[s - targetSum]
            prefix[s] += 1
            dfs(u.left)
            dfs(u.right)
            prefix[s] -= 1
            s -= u.val

        dfs(root)

        return result
