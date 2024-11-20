class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        char_sum = [0, 0, 0]
        for c in s:
            char_sum[ord(c) - ord("a")] += 1

        if min(char_sum) < k:
            return -1

        idx = lambda c: ord(c) - ord("a")

        r = len(s) - 1
        window = [0, 0, 0]
        while min(window) < k:
            window[idx(s[r])] += 1
            r -= 1

        r += 1
        result = len(s) - r

        for l in range(len(s)):
            window[idx(s[l])] += 1
            while r < len(s) and min(window) >= k:
                window[idx(s[r])] -= 1
                r += 1
            if min(window) >= k:
                r += 1
            result = min(result, l + 1 + len(s) - r + 1)

        return result
