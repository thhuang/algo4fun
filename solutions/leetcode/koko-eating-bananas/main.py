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


class Solution:

    def minEatingSpeed(self, piles: List[int], h: int) -> int:

        def feasible(v: int) -> bool:
            t = 0
            for p in piles:
                t += ceil(p / v)
            return t <= h

        l = 1
        r = max(piles)

        while l < r:
            m = (l + r) // 2
            if feasible(m):
                r = m
            else:
                l = m + 1

        return r
