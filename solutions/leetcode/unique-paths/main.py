class Solution:

    def uniquePaths(self, m: int, n: int) -> int:
        s = (m + n - 2)
        mn = min(m - 1, n - 1)
        result = 1
        for i in range(1, mn + 1):
            result *= s
            result /= i
            s -= 1
        return int(result)


class Solution:

    def uniquePaths(self, m: int, n: int) -> int:
        dp = [0 for _ in range(n)]
        dp[0] = 1
        for i in range(m):
            for j in range(1, n):
                dp[j] += dp[j - 1]
        return dp[-1]
