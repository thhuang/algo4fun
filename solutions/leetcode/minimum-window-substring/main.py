from collections import defaultdict


class Solution:

    def minWindow(self, s: str, t: str) -> str:
        cnt = len(t)
        freq = defaultdict(int)
        for c in t:
            freq[c] += 1

        begin, length = 0, len(s) + 1

        l = 0
        for r, c in enumerate(s):
            freq[c] -= 1
            if freq[c] >= 0:
                cnt -= 1

            while cnt == 0:
                if length > r - l + 1:
                    begin, length = l, r - l + 1
                freq[s[l]] += 1
                if freq[s[l]] > 0:
                    cnt += 1
                l += 1

        return s[begin:begin + length] if length <= len(s) else ""
