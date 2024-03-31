class Solution:

    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        result = 0

        window = dict()
        l = 0

        for r in range(len(s)):
            window[s[r]] = window.get(s[r], 0) + 1

            while len(window) > k:
                window[s[l]] -= 1
                if window[s[l]] == 0:
                    del window[s[l]]
                l += 1

            result = max(result, r - l + 1)

        return result
