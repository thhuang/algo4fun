# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def getLonelyNodes(self, root: Optional[TreeNode]) -> List[int]:
        result = []

        def dfs(u):
            nonlocal result

            if u is None:
                return False

            l = dfs(u.left)
            r = dfs(u.right)

            if l and not r:
                result.append(u.left.val)
            if r and not l:
                result.append(u.right.val)

            return True

        dfs(root)

        return result
