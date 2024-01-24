# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def pseudoPalindromicPaths(self, root: Optional[TreeNode]) -> int:

        def isPalindrome(freq):
            has_odd = False
            for v in freq:
                if v % 2 == 1:
                    if has_odd:
                        return False
                    has_odd = True
            return True

        result = 0
        freq = [0 for _ in range(10)]

        def dfs(u):
            nonlocal result
            nonlocal freq

            freq[u.val] += 1

            if u.left is None and u.right is None:
                if isPalindrome(freq):
                    result += 1
            else:
                if u.left is not None:
                    dfs(u.left)
                if u.right is not None:
                    dfs(u.right)

            freq[u.val] -= 1

        dfs(root)

        return result
