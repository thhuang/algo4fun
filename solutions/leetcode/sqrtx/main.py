class Solution:

    def mySqrt(self, x: int) -> int:
        l, r = 0, x + 1  # [l, r)
        while r - l > 1:
            m = (l + r) // 2
            if m * m <= x:
                l = m
            else:
                r = m
        return l
