class State:

    def __init__(self, full, half):
        self.full = full
        self.half = half


class Solution:

    def numTilings(self, n: int) -> int:
        mod = 10**9 + 7
        dp = [State(1, 0), State(1, 0)]
        for _ in range(1, n):
            dp[0], dp[1] = dp[1], State(
                (dp[0].full + dp[1].full + dp[1].half) % mod,
                (dp[0].full * 2 + dp[1].half) % mod,
            )
        return dp[1].full
