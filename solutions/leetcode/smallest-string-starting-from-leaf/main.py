# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        result = None

        curr = deque()

        def dfs(u):
            nonlocal result

            curr.appendleft(chr(u.val + ord("a")))

            if u.left is None and u.right is None:
                s = "".join(curr)
                if result is None or s < result:
                    result = s
            else:
                if u.left is not None:
                    dfs(u.left)
                if u.right is not None:
                    dfs(u.right)

            curr.popleft()

        dfs(root)

        return result
