class Solution:

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 0, max(piles)  # (l, r]

        while r - l > 1:
            m = (l + r) // 2
            v = 0
            for p in piles:
                v += ceil(p / m)
            if v > h:
                l = m
            else:
                r = m

        return r
