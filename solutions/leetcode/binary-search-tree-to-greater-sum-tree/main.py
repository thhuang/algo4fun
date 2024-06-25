# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def bstToGst(self, root: TreeNode) -> TreeNode:

        def process(u, s):
            if u is None:
                return 0

            v = u.val

            r = process(u.right, s)
            u.val += s + r
            l = process(u.left, u.val)

            return v + l + r

        process(root, 0)

        return root
