class Solution:

    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid[0])
        dp = grid[0]

        for row in grid[1:]:
            new_dp = [None] * n
            for i in range(n):
                new_dp[i] = row[i] + min(dp[:i] + dp[i + 1:])
            dp = new_dp

        return min(dp)
