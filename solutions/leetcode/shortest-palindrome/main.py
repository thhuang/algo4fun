class Solution:

    def shortestPalindrome(self, s: str) -> str:
        n = len(s)

        for i in range(n, 0, -1):
            if s[:i] == s[:i][::-1]:
                return s[i:][::-1] + s

        return ""


class Solution:

    def shortestPalindrome(self, s: str) -> str:
        mod = 1 << 31 - 1

        n = len(s)
        r = "".join(s[::-1])

        x = n + 1
        if x % 2 == 0:
            x += 1

        def getSuffixHash(s: str) -> List[str]:
            suffix_hash = [0] * (n + 1)
            for i in reversed(range(n)):
                suffix_hash[i] = (suffix_hash[i + 1] * x + ord(s[i]) - ord("a")) % mod
            return suffix_hash

        suffix_hash_s = getSuffixHash(s)
        suffix_hash_r = getSuffixHash(r)

        max_dist = 0
        y = 1
        for d in range(1, n + 1):
            y = y * x % mod
            a = (suffix_hash_s[0] - suffix_hash_s[d] * y + mod) % mod
            b = suffix_hash_r[n - d]
            if a == b:
                max_dist = d

        return r + s[max_dist:]
