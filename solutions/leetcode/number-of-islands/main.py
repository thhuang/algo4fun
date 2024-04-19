class Solution:

    def numIslands(self, grid: List[List[str]]) -> int:
        directions = ((1, 0), (-1, 0), (0, 1), (0, -1))

        m = len(grid)
        n = len(grid[0])

        def dfs(i, j):
            if i < 0 or m <= i or j < 0 or n <= j or grid[i][j] != "1":
                return False
            grid[i][j] = "2"
            for di, dj in directions:
                dfs(i + di, j + dj)
            return True

        result = 0

        for i in range(m):
            for j in range(n):
                if dfs(i, j):
                    result += 1

        return result
