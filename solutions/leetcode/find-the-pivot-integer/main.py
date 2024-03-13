class Solution:

    def pivotInteger(self, n: int) -> int:
        left = lambda x: (1 + x) * x // 2
        right = lambda x: (x + n) * (n - x + 1) // 2

        l, r = 1, n + 1  # [l, r)
        while r - l > 1:
            m = (l + r) // 2
            if left(m) <= right(m):
                l = m
            else:
                r = m

        return l if left(l) == right(l) else -1
