class Solution:

    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [0, 0]
        for i in range(len(cost)):
            dp[0], dp[1] = dp[1], min(dp) + cost[i]
        return min(dp)
