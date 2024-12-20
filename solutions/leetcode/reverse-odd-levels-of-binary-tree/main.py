# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        q = [root]

        while q[0] is not None and q[0].left is not None:
            b1 = []
            b2 = []

            for u in q:
                b1.append(u.left)
                b1.append(u.right)
            for u in b1:
                b2.append(u.left)
                b2.append(u.right)

            b1.reverse()

            for i, u in enumerate(q):
                u.left = b1[i * 2]
                u.right = b1[i * 2 + 1]
            for i, u in enumerate(b1):
                u.left = b2[i * 2]
                u.right = b2[i * 2 + 1]

            q = b2

        return root


class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return

        def dfs(l: Optional[TreeNode], r: Optional[TreeNode], lv: int):
            if l is None or r is None:
                return
            if lv % 2 == 1:
                l.val, r.val = r.val, l.val
            dfs(l.left, r.right, lv + 1)
            dfs(l.right, r.left, lv + 1)

        dfs(root.left, root.right, 1)

        return root
