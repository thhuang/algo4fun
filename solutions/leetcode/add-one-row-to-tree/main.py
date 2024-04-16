# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if depth == 1:
            return TreeNode(val=val, left=root)

        def search(u, d):
            if u is None:
                return
            if d == depth - 1:
                u.left = TreeNode(val=val, left=u.left)
                u.right = TreeNode(val=val, right=u.right)
                return
            search(u.left, d + 1)
            search(u.right, d + 1)

        search(root, 1)

        return root
