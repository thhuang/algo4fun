# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: Optional[TreeNode]):
        self.stack = [(root, False)]

    def next(self) -> int:
        while len(self.stack) > 0:
            u, visited = self.stack.pop()
            if visited:
                return u.val

            if u.right is not None:
                self.stack.append((u.right, False))
            self.stack.append((u, True))
            if u.left is not None:
                self.stack.append((u.left, False))

    def hasNext(self) -> bool:
        return len(self.stack) > 0


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
