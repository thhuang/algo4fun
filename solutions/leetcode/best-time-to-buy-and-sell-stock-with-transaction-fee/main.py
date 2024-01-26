class DP:

    def __init__(self, held, sold):
        self.held = held
        self.sold = sold


class Solution:

    def maxProfit(self, prices: List[int], fee: int) -> int:
        dp = DP(-inf, 0)
        for v in prices:
            dp = DP(max(dp.held, dp.sold - v), max(dp.sold, dp.held + v - fee))
        return dp.sold
