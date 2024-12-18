class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        idx = []
        for i, v in enumerate(prices):
            while len(idx) > 0 and prices[idx[-1]] >= v:
                prices[idx[-1]] -= v
                idx.pop()
            idx.append(i)
        return prices
