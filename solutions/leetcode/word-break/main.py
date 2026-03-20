class Solution:

    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False] * (n + 1)
        dp[-1] = True

        for i in range(0, n)[::-1]:
            for w in wordDict:
                m = len(w)
                if i + m > n or not dp[i + m] or s[i:i + m] != w:
                    continue
                dp[i] = True

        return dp[0]
