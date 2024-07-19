# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def countPairs(self, root: TreeNode, distance: int) -> int:
        result = 0

        def dfs(u: TreeNode) -> List[Tuple[int, int]]:
            if u is None:
                return []

            if u.left is None and u.right is None:
                return [(1, 1)]

            left_list = dfs(u.left)
            right_list = dfs(u.right)

            nonlocal result

            r = len(right_list) - 1
            right_cnt = 0
            for _, c in right_list:
                right_cnt += c

            for l in range(len(left_list)):
                while r >= 0 and left_list[l][0] + right_list[r][0] > distance:
                    right_cnt -= right_list[r][1]
                    r -= 1

                result += left_list[l][1] * right_cnt

            dist_cnt = defaultdict(int)
            for dc in left_list:
                dist_cnt[dc[0] + 1] += dc[1]
            for dc in right_list:
                dist_cnt[dc[0] + 1] += dc[1]

            return sorted([(d, c) for d, c in dist_cnt.items() if d < distance])

        dfs(root)

        return result
