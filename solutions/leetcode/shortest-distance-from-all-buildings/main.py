class Solution:

    def shortestDistance(self, grid: List[List[int]]) -> int:
        directions = ((0, 1), (1, 0), (0, -1), (-1, 0))

        m, n = len(grid), len(grid[0])
        buildings = sum([row.count(1) for row in grid])

        total_distance = [[0 for _ in range(n)] for _ in range(m)]
        reached = [[0 for _ in range(n)] for _ in range(m)]

        def bfs(start_i, start_j):
            nonlocal total_distance
            nonlocal reached

            visited = [[False for _ in range(n)] for _ in range(m)]
            q = deque()
            for di, dj in directions:
                q.append((start_i + di, start_j + dj, 1))

            while len(q) > 0:
                i, j, d = q.popleft()

                if not (0 <= i < m) or not (0 <= j < n) or visited[i][j] or grid[i][j] != 0:
                    continue
                visited[i][j] = True

                total_distance[i][j] += d
                reached[i][j] += 1

                for di, dj in directions:
                    q.append((i + di, j + dj, d + 1))

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    bfs(i, j)

        result = inf
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 and reached[i][j] == buildings:
                    result = min(result, total_distance[i][j])

        if result == inf:
            return -1
        return result
