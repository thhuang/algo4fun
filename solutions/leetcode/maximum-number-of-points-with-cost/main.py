class Solution:

    def maxPoints(self, points: List[List[int]]) -> int:
        m, n = len(points), len(points[0])
        dp = [0] * n

        for i in range(m):
            new_dp = [-inf] * n

            mx = 0
            for j in range(n):
                mx = max(mx - 1, dp[j])
                new_dp[j] = mx

            mx = 0
            for j in reversed(range(n)):
                mx = max(mx - 1, dp[j])
                new_dp[j] = max(new_dp[j], mx) + points[i][j]

            dp = new_dp

        return max(dp)
