# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        result = 0

        q = [root]
        while len(q) > 0:
            q_new = []
            vals = []

            for u in q:
                if u.left is not None:
                    q_new.append(u.left)
                if u.right is not None:
                    q_new.append(u.right)

                unordered = 0
                vals.append(u.val)

            idx = {got: i for i, got in enumerate(vals)}
            for i, want in enumerate(sorted(vals)):
                if want != vals[i]:
                    j = idx[want]
                    vals[i], vals[j] = vals[j], vals[i]
                    idx[vals[i]] = i
                    idx[vals[j]] = j
                    result += 1

            q = q_new

        return result
