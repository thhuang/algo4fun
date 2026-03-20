# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def search(self, root: Optional[TreeNode]) -> Tuple[int, int]:
        if root is None:
            return [0, 0]

        lo, lx = self.search(root.left)
        ro, rx = self.search(root.right)

        return [lx + rx + root.val, max(lo, lx) + max(ro, rx)]

    def rob(self, root: Optional[TreeNode]) -> int:
        return max(self.search(root))
