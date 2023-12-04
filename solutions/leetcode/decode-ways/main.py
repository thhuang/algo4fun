class Solution:

    def numDecodings(self, s: str) -> int:
        if s[0] == "0":
            return 0
        if len(s) == 1:
            return 1

        valid = {str(i + 1) for i in range(26)}

        dp = [1, 0 if s[1] == "0" else 1]
        if s[0:2] in valid:
            dp[1] += 1

        for i in range(2, len(s)):
            dp = [
                dp[1],
                (0 if s[i] == "0" else dp[1]) +
                (dp[0] if s[i - 1:i + 1] in valid else 0),
            ]

        return dp[1]


class Solution:

    def numDecodings(self, s: str) -> int:
        if s[0] == "0":
            return 0

        valid = {str(i + 1) for i in range(26)}

        dp = [1, 1]
        for i in range(1, len(s)):
            dp = [
                dp[1],
                (0 if s[i] == "0" else dp[1]) +
                (dp[0] if s[i - 1:i + 1] in valid else 0),
            ]

        return dp[1]
