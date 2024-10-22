# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        sums = []

        def dfs(u: Optional[TreeNode], lv: int) -> None:
            nonlocal sums

            if u is None:
                return

            if lv == len(sums):
                sums.append(0)

            sums[lv] += u.val

            dfs(u.left, lv + 1)
            dfs(u.right, lv + 1)

        dfs(root, 0)

        if k > len(sums):
            return -1

        return sorted(sums, reverse=True)[k - 1]
