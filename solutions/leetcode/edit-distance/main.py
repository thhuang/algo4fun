class Solution:

    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)

        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in reversed(range(m)):
            dp[i][n] = m - i
        for j in reversed(range(n)):
            dp[m][j] = n - j

        for i in reversed(range(m)):
            for j in reversed(range(n)):
                if word1[i] == word2[j]:
                    dp[i][j] = dp[i + 1][j + 1]
                else:
                    dp[i][j] = 1 + min(dp[i][j + 1], dp[i + 1][j],
                                       dp[i + 1][j + 1])

        return dp[0][0]


class Solution:

    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)

        dp = [0] * (n + 1)
        for j in reversed(range(n)):
            dp[j] = n - j

        for i in reversed(range(m)):
            dp_new = [0] * (n + 1)
            dp_new[n] = m - i
            for j in reversed(range(n)):
                if word1[i] == word2[j]:
                    dp_new[j] = dp[j + 1]
                else:
                    dp_new[j] = 1 + min(dp_new[j + 1], dp[j], dp[j + 1])
            dp = dp_new

        return dp[0]
