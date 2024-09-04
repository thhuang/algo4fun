# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []

        ordered_nodes = defaultdict(lambda: [])
        mn, mx = 1, -1
        q = deque([(root, 0)])

        while len(q) > 0:
            u, i = q.popleft()
            ordered_nodes[i].append(u.val)
            mn = min(mn, i)
            mx = max(mx, i)
            if u.left is not None:
                q.append((u.left, i - 1))
            if u.right is not None:
                q.append((u.right, i + 1))

        result = []
        for i in range(mn, mx + 1):
            result.append(ordered_nodes[i])

        return result
