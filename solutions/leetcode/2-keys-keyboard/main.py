class Solution:

    def minSteps(self, n: int) -> int:
        dp = [i for i in range(n + 1)]
        dp[1] = 0
        for l in range(2, n // 2):
            d = dp[l] + 2
            for r in range(l * 2, n + 1, l):
                dp[r] = min(dp[r], d)
                d += 1
        return dp[-1]


class Solution:

    def minSteps(self, n: int) -> int:
        result = 0
        p = 2
        while p <= n:
            while n % p == 0:
                result += p
                n /= p
            p += 1
        return result
