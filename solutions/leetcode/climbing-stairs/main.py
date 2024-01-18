class Solution:

    def climbStairs(self, n: int) -> int:
        dp = [1, 1]
        for _ in range(2, n + 1):
            dp[0], dp[1] = dp[1], dp[0] + dp[1]
        return dp[1]
