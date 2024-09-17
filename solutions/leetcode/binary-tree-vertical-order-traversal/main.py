# Definition for a binary tree node.# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []

        col_to_vals = defaultdict(lambda: [])
        mn, mx = 0, 0
        q = deque([(root, 0)])

        while len(q) > 0:
            u, c = q.popleft()

            col_to_vals[c].append(u.val)

            mn = min(mn, c)
            mx = max(mx, c)

            if u.left is not None:
                q.append((u.left, c - 1))
            if u.right is not None:
                q.append((u.right, c + 1))

        return [col_to_vals[i] for i in range(mn, mx + 1)]
