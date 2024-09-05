class Solution:

    def minWindow(self, s: str, t: str) -> str:
        m = len(s)
        n = len(t)
        freq = defaultdict(int)
        for c in t:
            freq[c] += 1

        start, length = 0, m + 1
        l = 0
        for r in range(len(s)):
            freq[s[r]] -= 1
            if freq[s[r]] >= 0:
                n -= 1

            while n == 0:
                if r - l + 1 < length:
                    start, length = l, r - l + 1
                freq[s[l]] += 1
                if freq[s[l]] > 0:
                    n += 1
                l += 1

        if length > m:
            return ""
        return s[start:start + length]
