class Solution:

    def strStr(self, haystack: str, needle: str) -> int:
        m, n = len(haystack), len(needle)

        x = m + 1
        if x % 2 == 1:
            x += 1

        suffix_hash = [0] * (m + 1)
        for i in reversed(range(m)):
            suffix_hash[i] = (ord(haystack[i]) - ord("a")) + suffix_hash[i + 1] * x

        t = 0
        xn = 1
        for c in needle:
            t += (ord(c) - ord("a")) * xn
            xn *= x

        for l in range(m - n + 1):
            r = l + n
            v = suffix_hash[l] - xn * suffix_hash[r]
            if v == t:
                return l

        return -1
