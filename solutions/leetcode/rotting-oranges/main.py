class Solution:

    def orangesRotting(self, grid: List[List[int]]) -> int:
        directions = ((1, 0), (0, 1), (-1, 0), (0, -1))

        m = len(grid)
        n = len(grid[0])

        q = deque()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    q.append((i, j, 0))

        vis = [[-1] * n for _ in range(m)]

        while len(q) > 0:
            i, j, t = q.popleft()

            if i < 0 or m <= i or j < 0 or n <= j or grid[i][j] == 0 or vis[i][
                    j] != -1:
                continue

            vis[i][j] = t

            for di, dj in directions:
                q.append((i + di, j + dj, t + 1))

        result = 0
        for i in range(m):
            for j in range(n):
                if vis[i][j] == -1 and grid[i][j] == 1:
                    return -1
                result = max(result, vis[i][j])

        return result
