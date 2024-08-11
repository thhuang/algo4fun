class Solution:

    def minDays(self, grid: List[List[int]]) -> int:
        if self.numIslands(grid) != 1:
            return 0
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    if self.numIslands(grid) != 1:
                        return 1
                    grid[i][j] = 1
        return 2

    def numIslands(self, grid: List[List[int]]) -> int:
        directions = ((1, 0), (0, 1), (-1, 0), (0, -1))
        vis = set()
        m, n = len(grid), len(grid[0])

        def dfs(i: int, j: int):
            if i < 0 or m <= i or j < 0 or n <= j or grid[i][j] == 0 or (i, j) in vis:
                return
            vis.add((i, j))
            for di, dj in directions:
                dfs(i + di, j + dj)

        result = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1 and (i, j) not in vis:
                    dfs(i, j)
                    result += 1
        return result
