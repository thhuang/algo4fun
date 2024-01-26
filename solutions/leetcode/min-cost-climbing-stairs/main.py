class Solution:

    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [0, 0]
        for c in cost:
            dp[0], dp[1] = dp[1], min(dp) + c
        return min(dp)
