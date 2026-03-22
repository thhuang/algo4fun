class Solution:

    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [inf] * (amount + 1)
        dp[0] = 0

        for i in range(len(dp)):
            for c in coins:
                if i - c >= 0 and dp[i - c] <= amount:
                    dp[i] = min(dp[i], dp[i - c] + 1)

        return dp[amount] if dp[amount] <= amount else -1
