# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:

        def process(u):
            if u is None:
                return True

            l = process(u.left)
            if l:
                u.left = None

            r = process(u.right)
            if r:
                u.right = None

            return l and r and u.val == target

        if process(root) and root.val == target:
            return None

        return root


class Solution:

    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        if root is None:
            return None
        root.left = self.removeLeafNodes(root.left, target)
        root.right = self.removeLeafNodes(root.right, target)
        return None if root.left is None and root.right is None and root.val == target else root
