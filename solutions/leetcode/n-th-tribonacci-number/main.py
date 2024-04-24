class Solution:

    def tribonacci(self, n: int) -> int:
        dp = [0, 1, 1]
        if n < 3:
            return dp[n]
        for _ in range(3, n + 1):
            dp[:] = [dp[1], dp[2], sum(dp)]
        return dp[-1]
