from collections import deque


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
