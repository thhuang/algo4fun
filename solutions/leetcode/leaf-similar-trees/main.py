# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def leafSimilar(self, root1: Optional[TreeNode],
                    root2: Optional[TreeNode]) -> bool:

        def collect(u, leaves):
            if u.left is None and u.right is None:
                leaves.append(u.val)
                return
            if u.left is not None:
                collect(u.left, leaves)
            if u.right is not None:
                collect(u.right, leaves)

        leaves1, leaves2 = [], []
        collect(root1, leaves1)
        collect(root2, leaves2)

        return leaves1 == leaves2


class Solution:

    def leafSimilar(self, root1: Optional[TreeNode],
                    root2: Optional[TreeNode]) -> bool:

        def collect(u: Optional[TreeNode], leaves: List[int]) -> None:
            if u.left is None and u.right is None:
                leaves.append(u.val)
                return leaves
            if u.left is not None:
                collect(u.left, leaves)
            if u.right is not None:
                collect(u.right, leaves)
            return leaves

        return collect(root1, []) == collect(root2, [])
