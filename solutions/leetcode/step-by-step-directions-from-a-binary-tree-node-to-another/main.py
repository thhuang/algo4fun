# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def getDirections(self, root: Optional[TreeNode], start_value: int, dest_value: int) -> str:
        start_path, dest_path = None, None
        path = []

        def dfs(u):
            nonlocal start_path
            nonlocal dest_path
            nonlocal path

            if u is None:
                return
            elif u.val == start_value:
                start_path = path.copy()
            elif u.val == dest_value:
                dest_path = path.copy()

            path.append("L")
            dfs(u.left)
            path.pop()

            path.append("R")
            dfs(u.right)
            path.pop()

        dfs(root)

        p = 0
        while p < len(start_path) and p < len(dest_path) and start_path[p] == dest_path[p]:
            p += 1

        return "".join(["U"] * (len(start_path) - p) + dest_path[p:])
