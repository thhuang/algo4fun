# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        prev = -inf

        def inorder(u: Optional[TreeNode]):
            nonlocal prev

            if u is None:
                return True

            if not inorder(u.left):
                return False

            if u.val <= prev:
                return False
            prev = u.val

            if not inorder(u.right):
                return False

            return True

        return inorder(root)


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True

        q = [(root, -inf, inf)]

        while len(q) > 0:
            nq = []

            for (u, l, r) in q:
                if u.left is not None:
                    if l < u.left.val < u.val:
                        nq.append((u.left, l, u.val))
                    else:
                        return False

                if u.right is not None:
                    if u.val < u.right.val < r:
                        nq.append((u.right, u.val, r))
                    else:
                        return False

            q = nq

        return True


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True

        q = deque([(root, -inf, inf)])

        while q:
            node, left, right = q.popleft()

            if node.left:
                if left < node.left.val < node.val:
                    q.append([node.left, left, node.val])
                else:
                    return False

            if node.right:
                if node.val < node.right.val < right:
                    q.append([node.right, node.val, right])
                else:
                    return False

        return True
