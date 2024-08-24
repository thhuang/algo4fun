class Solution:

    def nearestPalindromic(self, s: str) -> str:
        n = len(s)
        t = int(s)

        def mirrow(l):
            result = l
            if n % 2 == 1:
                l //= 10
            while l > 0:
                result = result * 10 + l % 10
                l //= 10
            return result

        left = int(s[:(n + 1) // 2])

        candidates = [
            10**(n - 1) - 1,
            10**n + 1,
            mirrow(left),
            mirrow(left + 1),
            mirrow(left - 1),
        ]

        result, min_diff = float('inf'), float('inf')
        for v in candidates:
            diff = abs(t - v)
            if v == t:
                continue
            if (diff < min_diff) or (diff == min_diff and v < result):
                result, min_diff = v, diff

        return str(result)
