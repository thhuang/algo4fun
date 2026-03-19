# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []

        result = []
        q = [root]

        while len(q) > 0:
            result.append([])
            nq = []

            for u in q:
                result[-1].append(u.val)

                for v in [u.left, u.right]:
                    if v is not None:
                        nq.append(v)

            q = nq

        return result
