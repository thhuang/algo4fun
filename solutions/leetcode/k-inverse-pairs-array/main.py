class Solution:

    def kInversePairs(self, n: int, k: int) -> int:
        mod = 10**9 + 7
        dp = [[0] * (k + 1) for _ in range(n + 1)]
        dp[0][0] = 1
        for i in range(1, n + 1):
            v = 0
            for j in range(k + 1):
                v += dp[i - 1][j]
                if j > i - 1:
                    v -= dp[i - 1][j - i]
                dp[i][j] = (dp[i][j] + v) % mod
        return dp[n][k]
