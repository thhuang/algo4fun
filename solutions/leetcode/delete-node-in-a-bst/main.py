# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def deleteNode(self, root: Optional[TreeNode],
                   key: int) -> Optional[TreeNode]:
        if root is None:
            return None
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
            return root
        if key > root.val:
            root.right = self.deleteNode(root.right, key)
            return root
        if root.right is None:
            return root.left

        u = root.right
        while u.left is not None:
            u = u.left
        root.right = self.deleteNode(root.right, u.val)
        u.left, u.right = root.left, root.right
        return u
