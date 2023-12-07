class Solution:

    def scoreOfParentheses(self, s: str) -> int:
        s = "(" + s + ")"

        dp = [[-1] * len(s) for _ in range(len(s))]

        for i in range(len(s) - 1):
            if s[i] == "(" and s[i + 1] == ")":
                dp[i][i + 1] = 1

        for length in range(4, len(s) + 1, 2):
            for r in range(length - 1, len(s)):
                l = r - length + 1
                if s[l] != "(" or s[r] != ")":
                    continue
                if dp[l + 1][r - 1] != -1:
                    dp[l][r] = dp[l + 1][r - 1] * 2
                    continue
                for i in range(l + 1, r - 1):
                    if dp[l][i] != -1 and dp[i + 1][r] != -1:
                        dp[l][r] = dp[l][i] + dp[i + 1][r]
                        break

        return dp[0][-1] // 2
