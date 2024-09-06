class Solution:

    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        directions = ((1, 1), (1, 0), (1, -1), (0, 1), (0, -1), (-1, 1), (-1, 0), (-1, -1))

        n = len(grid)

        q = deque()
        q.append((0, 0, 1))  # (i, j, dist)

        vis = [[False for _ in range(n)] for _ in range(n)]

        while len(q) > 0:
            i, j, dist = q.popleft()

            if not (0 <= i < n) or not (0 <= j < n) or vis[i][j] or grid[i][j] == 1:
                continue
            vis[i][j] = True

            if i == n - 1 and j == n - 1:
                return dist

            for di, dj in directions:
                q.append((i + di, j + dj, dist + 1))

        return -1
