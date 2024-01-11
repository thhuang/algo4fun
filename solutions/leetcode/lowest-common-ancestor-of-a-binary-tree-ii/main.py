# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode',
                             q: 'TreeNode') -> 'TreeNode':

        def search(u: 'TreeNode', target: 'TreeNode',
                   path: List['TreeNode']) -> bool:
            if u is None:
                return False

            path.append(u)
            if u == target:
                return True
            if search(u.left, target, path):
                return True
            if search(u.right, target, path):
                return True
            path.pop()

        p_path = []
        search(root, p, p_path)

        q_path = []
        search(root, q, q_path)

        result = None
        for i in range(min(len(p_path), len(q_path))):
            if p_path[i] != q_path[i]:
                break
            result = p_path[i]

        return result
