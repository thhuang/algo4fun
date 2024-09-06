class Solution:

    def strStr(self, haystack: str, needle: str) -> int:
        m, n = len(haystack), len(needle)

        x = m + 1
        if x % 2 == 0:
            x += 1

        suffix_hash = [0] * (m + 1)
        for i, c in reversed(list(enumerate(haystack))):
            suffix_hash[i] = ord(c) - ord("a") + x * suffix_hash[i + 1]

        t = 0
        xn = 1
        for i, c in enumerate(needle):
            t += xn * (ord(c) - ord("a"))
            xn *= x

        for l in range(m - n + 1):
            r = l + n
            v = suffix_hash[l] - xn * suffix_hash[r]
            if v == t:
                return l

        return -1
