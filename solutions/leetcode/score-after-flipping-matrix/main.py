class Solution:

    def matrixScore(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        def flipRow(r):
            for c in range(n):
                grid[r][c] = -(grid[r][c] - 1)

        def flipCol(c):
            for r in range(m):
                grid[r][c] = -(grid[r][c] - 1)

        for i in range(m):
            if grid[i][0] == 0:
                flipRow(i)

        for j in range(1, n):
            one_count = 0
            for i in range(m):
                one_count += grid[i][j]
            if one_count < m / 2:
                flipCol(j)

        result = 0
        for row in grid:
            for i, v in enumerate(row):
                result += v * 2**(n - 1 - i)

        return result
