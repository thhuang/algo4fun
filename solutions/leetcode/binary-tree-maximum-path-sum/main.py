# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        result = -inf

        def search(node: TreeNode) -> int:
            nonlocal result

            l = 0
            if node.left is not None:
                l = max(l, search(node.left))

            r = 0
            if node.right is not None:
                r = max(r, search(node.right))

            result = max(result, node.val + l + r)

            return node.val + max(l, r)

        search(root)

        return result


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        result = -inf

        def search(node: Optional[TreeNode]) -> int:
            nonlocal result

            if node is None:
                return 0

            l = max(0, search(node.left))
            r = max(0, search(node.right))

            result = max(result, node.val + l + r)

            return node.val + max(l, r)

        search(root)

        return result
