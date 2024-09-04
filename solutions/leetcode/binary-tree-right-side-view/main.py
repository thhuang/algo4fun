# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        q = collections.deque()
        if root:
            q.append(root)

        result = []

        while len(q) > 0:
            n = len(q)
            result.append(q[0].val)
            for _ in range(n):
                u = q.popleft()
                if u.right:
                    q.append(u.right)
                if u.left:
                    q.append(u.left)

        return result


class Solution:

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []

        result = []
        q = deque()
        q.append(root)

        while len(q) > 0:
            n = len(q)
            result.append(q[0].val)
            for _ in range(n):
                u = q.popleft()
                if u.right is not None:
                    q.append(u.right)
                if u.left is not None:
                    q.append(u.left)

        return result
