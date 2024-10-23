# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        sums = []

        def calculateLevelSum(u: Optional[TreeNode], lv: int):
            nonlocal sums

            if u is None:
                return

            if lv == len(sums):
                sums.append(0)

            sums[lv] += u.val

            calculateLevelSum(u.left, lv + 1)
            calculateLevelSum(u.right, lv + 1)

        def buildTree(u: Optional[TreeNode], p: Optional[TreeNode], lv: int) -> Optional[TreeNode]:
            nonlocal sums

            if u is None:
                return None

            v = sums[lv]
            if p is not None:
                if p.left is not None:
                    v -= p.left.val
                if p.right is not None:
                    v -= p.right.val

            return TreeNode(v, buildTree(u.left, u, lv + 1), buildTree(u.right, u, lv + 1))

        calculateLevelSum(root, 0)

        return buildTree(root, TreeNode(left=root), 0)
