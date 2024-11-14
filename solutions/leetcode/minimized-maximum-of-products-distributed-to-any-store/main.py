class Solution:

    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        total = sum(quantities)

        def check(mx: int) -> bool:
            cnt = 0
            for q in quantities:
                cnt += ceil(q / mx)
            return cnt <= n

        l = 0
        r = total
        while r - l > 1:
            m = l + (r - l) // 2
            if check(m):
                r = m
            else:
                l = m

        return r
