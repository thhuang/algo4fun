class Solution:

    def kInversePairs(self, n: int, k: int) -> int:
        dp = [[0] * (k + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            dp[i][0] = 1
        for i in range(1, n + 1):
            for j in range(1, k + 1):
                for d in range(0, j + 1):
                    if d > i - 1:
                        continue
                    dp[i][j] += dp[i - 1][j - d]
        return dp[n][k]


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


class Solution:

    def kInversePairs(self, n: int, k: int) -> int:
        mod = 10**9 + 7
        dp = [[0] * (k + 1) for _ in range(n + 1)]
        dp[0][0] = 1
        for i in range(1, n + 1):
            v = 0
            for r in range(k + 1):
                l = r - i
                v += dp[i - 1][r]
                if l >= 0:
                    v -= dp[i - 1][l]
                dp[i][r] = (dp[i][r] + v) % mod
        return dp[n][k]
