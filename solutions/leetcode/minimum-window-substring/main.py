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


class Solution:

    def minWindow(self, s: str, t: str) -> str:
        result = ""

        matched = 0
        window = defaultdict(lambda: 0)
        for c in t:
            window[c] += 1

        l = 0
        for r in range(len(s)):
            if window[s[r]] > 0:
                matched += 1
            window[s[r]] -= 1

            while matched == len(t):
                if result == "" or len(result) > r - l + 1:
                    result = s[l:r + 1]

                if window[s[l]] >= 0:
                    matched -= 1
                window[s[l]] += 1

                l += 1

        return result


class Solution:

    def minWindow(self, s: str, t: str) -> str:
        window = defaultdict(int)
        for c in t:
            window[c] += 1

        left, right = -1, len(s)
        matched = 0

        l = 0
        for r in range(len(s)):
            if window[s[r]] > 0:
                matched += 1
            window[s[r]] -= 1

            while matched == len(t):
                if right - left > r - l:
                    left, right = l, r

                if window[s[l]] >= 0:
                    matched -= 1
                window[s[l]] += 1

                l += 1

        return "" if right - left + 1 > len(s) else s[left:right + 1]
