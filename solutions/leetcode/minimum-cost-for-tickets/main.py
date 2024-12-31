class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        n = len(days)

        dp = [float("inf")] * (n + 1)
        dp[-1] = 0

        for l in reversed(range(n)):
            for c, d in zip(costs, (1, 7, 30)):
                r = bisect_left(days, days[l] + d)
                dp[l] = min(dp[l], dp[r] + c)

        return dp[0]
