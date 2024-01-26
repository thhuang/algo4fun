class Solution:

    def findPaths(self, m: int, n: int, maxMove: int, startRow: int,
                  startColumn: int) -> int:
        directions = ((0, 1), (0, -1), (1, 0), (-1, 0))

        @cache
        def dfs(i, j, move):
            nonlocal m
            nonlocal n

            if i < 0 or m <= i or j < 0 or n <= j:
                return 1
            if move == 0:
                return 0

            result = 0
            for di, dj in directions:
                result += dfs(i + di, j + dj, move - 1)

            return result % (10**9 + 7)

        return dfs(startRow, startColumn, maxMove)


class Solution:

    def findPaths(self, m: int, n: int, maxMove: int, startRow: int,
                  startColumn: int) -> int:
        directions = ((1, 0), (-1, 0), (0, 1), (0, -1))

        dp = [[[0 for _ in range(maxMove + 1)] for _ in range(n)]
              for _ in range(m)]

        for k in range(1, maxMove + 1):
            for i in range(m):
                for j in range(n):
                    for di, dj in directions:
                        ii, jj = i + di, j + dj
                        if ii < 0 or m <= ii or jj < 0 or n <= jj:
                            dp[i][j][k] += 1
                        else:
                            dp[i][j][k] += dp[ii][jj][k - 1]
                    dp[i][j][k] %= 10**9 + 7

        return dp[startRow][startColumn][maxMove]
