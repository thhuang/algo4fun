class Solution:

    def ways(self, pizza: List[str], k: int) -> int:
        m, n = len(pizza), len(pizza[0])

        suffix_sum = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        for i in reversed(range(m)):
            for j in reversed(range(n)):
                suffix_sum[i][j] = suffix_sum[i + 1][j] + suffix_sum[i][j + 1] - suffix_sum[i + 1][j + 1] + (
                    1 if pizza[i][j] == "A" else 0)

        @cache
        def dp(i, j, k):
            if suffix_sum[i][j] == 0:
                return 0
            if k == 1:
                return 1

            result = 0

            for ii in range(i + 1, m):
                if suffix_sum[i][j] - suffix_sum[ii][j] > 0:
                    result += dp(ii, j, k - 1)
            for jj in range(j + 1, n):
                if suffix_sum[i][j] - suffix_sum[i][jj] > 0:
                    result += dp(i, jj, k - 1)

            return result

        return dp(0, 0, k) % (10**9 + 7)


class Solution:

    def ways(self, pizza: List[str], k: int) -> int:
        m, n = len(pizza), len(pizza[0])

        suffix_sum = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        for i in reversed(range(m)):
            for j in reversed(range(n)):
                suffix_sum[i][j] = suffix_sum[i + 1][j] + suffix_sum[i][j + 1] - suffix_sum[i + 1][j + 1] + (
                    1 if pizza[i][j] == "A" else 0)

        dp = [[[0 for _ in range(k)] for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if suffix_sum[i][j] > 0:
                    dp[i][j][k - 1] = 1

        for kk in reversed(range(k - 1)):
            for i in reversed(range(m)):
                for j in reversed(range(n)):
                    for ii in range(i + 1, m):
                        if suffix_sum[i][j] - suffix_sum[ii][j] > 0:
                            dp[i][j][kk] += dp[ii][j][kk + 1]
                    for jj in range(j + 1, n):
                        if suffix_sum[i][j] - suffix_sum[i][jj] > 0:
                            dp[i][j][kk] += dp[i][jj][kk + 1]

        return dp[0][0][0] % (10**9 + 7)


class Solution:

    def ways(self, pizza: List[str], k: int) -> int:
        m, n = len(pizza), len(pizza[0])

        suffix_sum = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        for i in reversed(range(m)):
            for j in reversed(range(n)):
                suffix_sum[i][j] = suffix_sum[i + 1][j] + suffix_sum[i][j + 1] - suffix_sum[i + 1][j + 1] + (
                    1 if pizza[i][j] == "A" else 0)

        dp = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if suffix_sum[i][j] > 0:
                    dp[i][j] = 1

        for _ in range(k - 1):
            dp_new = [[0 for _ in range(n)] for _ in range(m)]
            for i in reversed(range(m)):
                for j in reversed(range(n)):
                    for ii in range(i + 1, m):
                        if suffix_sum[i][j] - suffix_sum[ii][j] > 0:
                            dp_new[i][j] += dp[ii][j]
                    for jj in range(j + 1, n):
                        if suffix_sum[i][j] - suffix_sum[i][jj] > 0:
                            dp_new[i][j] += dp[i][jj]
            dp = dp_new

        return dp[0][0] % (10**9 + 7)
