class Solution:

    def minCost(self, costs: List[List[int]]) -> int:
        dp = (0, 0, 0)
        for cost in costs:
            dp = (min(dp[1], dp[2]) + cost[0], min(dp[0], dp[2]) + cost[1],
                  min(dp[0], dp[1]) + cost[2])
        return min(dp)
