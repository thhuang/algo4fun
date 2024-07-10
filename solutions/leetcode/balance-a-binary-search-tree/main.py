# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def balanceBST(self, root: TreeNode) -> TreeNode:

        def inorder(u, values):
            if u is None:
                return
            inorder(u.left, values)
            values.append(u.val)
            inorder(u.right, values)

        def construct(l, r):
            if l > r:
                return
            m = (l + r) // 2
            return TreeNode(values[m], construct(l, m - 1), construct(m + 1, r))

        values = []
        inorder(root, values)
        return construct(0, len(values) - 1)
