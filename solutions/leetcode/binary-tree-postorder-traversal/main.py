# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []

        def postorder(u: Optional[TreeNode]):
            nonlocal result
            if u is None:
                return
            postorder(u.left)
            postorder(u.right)
            result.append(u.val)

        postorder(root)
        return result
