# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def pathSum(self, root: Optional[TreeNode], target_sum: int) -> List[List[int]]:
        result = []

        curr_sum = 0
        curr_path = []

        def dfs(u: Optional[TreeNode]):
            nonlocal result
            nonlocal curr_sum
            nonlocal curr_path

            if u is None:
                return

            curr_sum += u.val
            curr_path.append(u.val)

            if u.left is None and u.right is None:
                if curr_sum == target_sum:
                    result.append(curr_path.copy())
            else:
                dfs(u.left)
                dfs(u.right)

            curr_path.pop()
            curr_sum -= u.val

        dfs(root)

        return result
