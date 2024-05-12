class Solution:

    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        result = [[0] * (n - 2) for _ in range(m - 2)]
        for i in range(m - 2):
            for j in range(n - 2):
                for di in range(3):
                    for dj in range(3):
                        result[i][j] = max(result[i][j], grid[i + di][j + dj])
        return result
