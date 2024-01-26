class Solution:

    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)

        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for i in reversed(range(m)):
            for j in reversed(range(n)):
                if text1[i] == text2[j]:
                    dp[i][j] = 1 + dp[i + 1][j + 1]
                else:
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j])

        return dp[0][0]


class Solution:

    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        dp = [0] * (n + 1)
        for i in reversed(range(m)):
            new_dp = [0] * (n + 1)
            for j in reversed(range(n)):
                if text1[i] == text2[j]:
                    new_dp[j] = 1 + dp[j + 1]
                else:
                    new_dp[j] = max(new_dp[j + 1], dp[j])
            dp = new_dp
        return dp[0]
