class Solution:

    def isMatch(self, s: str, p: str) -> bool:
        m = len(s)
        n = len(p)

        dp = [False] * (n + 1)
        dp[0] = True
        for jj in range(1, n + 1):
            if p[jj - 1] == "*":
                dp[jj] = dp[jj - 1]

        for ii in range(1, m + 1):
            dp_new = [False] * (n + 1)
            for jj in range(1, n + 1):
                i = ii - 1
                j = jj - 1
                if p[j] == "*":
                    dp_new[jj] = dp_new[jj - 1] or dp[jj]
                elif s[i] == p[j] or p[j] == "?":
                    dp_new[jj] = dp[jj - 1]
            dp = dp_new

        return dp[-1]
