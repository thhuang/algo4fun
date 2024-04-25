class Solution:

    def longestIdealString(self, s: str, k: int) -> int:
        dp = [0] * 26
        for c in s:
            p = ord(c) - ord("a")
            l = max(0, p - k)
            r = min(len(dp), p + k + 1)
            dp[p] = max(dp[l:r]) + 1
        return max(dp)
