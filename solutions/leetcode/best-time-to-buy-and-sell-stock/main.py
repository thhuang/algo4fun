class Solution:

    def maxProfit(self, prices: List[int]) -> int:
        result = 0
        mn = prices[0]
        for v in prices:
            result = max(result, v - mn)
            mn = min(mn, v)
        return result
