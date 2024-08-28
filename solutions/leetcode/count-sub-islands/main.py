class Solution:

    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        directions = ((1, 0), (-1, 0), (0, 1), (0, -1))
        m, n = len(grid1), len(grid1[0])
        vis = [[0 for _ in range(n)] for _ in range(m)]

        def dfs(i: int, j: int) -> bool:
            if i < 0 or m <= i or j < 0 or n <= j:
                return True
            if vis[i][j] == 1:
                return True
            if vis[i][j] == -1:
                return False
            if grid2[i][j] == 0:
                return True
            if grid1[i][j] == 0:
                return False

            vis[i][j] = 1

            result = True
            for di, dj in directions:
                result = result and dfs(i + di, j + dj)

            if not result:
                vis[i][j] = -1

            return result

        result = 0
        for i in range(m):
            for j in range(n):
                if grid2[i][j] == 0 or vis[i][j]:
                    continue
                if dfs(i, j):
                    result += 1

        return result
