# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        to_delete_set = set(to_delete)

        result = []

        def dfs(u):
            if u is None:
                return None

            u.left = dfs(u.left)
            u.right = dfs(u.right)

            if u.val not in to_delete_set:
                return u

            if u.left is not None:
                result.append(u.left)
            if u.right is not None:
                result.append(u.right)

            return None

        u = dfs(root)
        if u is not None:
            result.append(u)

        return result
