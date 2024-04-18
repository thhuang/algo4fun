class Solution:

    def islandPerimeter(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        directions = ((1, 0), (-1, 0), (0, 1), (0, -1))

        result = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    continue
                for di, dj in directions:
                    ii = i + di
                    jj = j + dj
                    if 0 <= ii < m and 0 <= jj < n and grid[ii][jj] == 1:
                        continue
                    result += 1

        return result
