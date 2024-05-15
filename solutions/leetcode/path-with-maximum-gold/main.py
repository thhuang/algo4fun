class Solution:

    def getMaximumGold(self, grid: List[List[int]]) -> int:
        directions = ((1, 0), (-1, 0), (0, 1), (0, -1))

        m, n = len(grid), len(grid[0])

        result = 0

        def dfs(i, j, gold):
            nonlocal grid
            nonlocal result

            if i < 0 or m <= i or j < 0 or n <= j or grid[i][j] == 0:
                return

            v = grid[i][j]
            gold += v
            result = max(result, gold)

            grid[i][j] -= v

            for di, dj in directions:
                dfs(i + di, j + dj, gold)

            grid[i][j] += v

        for i in range(m):
            for j in range(n):
                dfs(i, j, 0)

        return result
