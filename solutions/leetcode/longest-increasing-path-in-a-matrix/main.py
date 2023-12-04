class Solution:

    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        directions = ((1, 0), (-1, 0), (0, 1), (0, -1))

        m = len(matrix)
        n = len(matrix[0])

        memo = dict()

        def dfs(i: int, j: int, p: int) -> int:
            if i < 0 or m <= i or j < 0 or n <= j or matrix[i][j] <= p:
                return 0
            if (i, j) in memo:
                return memo[(i, j)]

            result = 0
            for di, dj in directions:
                result = max(result, dfs(i + di, j + dj, matrix[i][j]))
            result += 1

            memo[(i, j)] = result

            return result

        result = 0
        for i in range(m):
            for j in range(n):
                result = max(result, dfs(i, j, -1))

        return result
