class Solution:

    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        directions = ((1, 0), (0, 1), (-1, 0), (0, -1))

        m, n = len(maze), len(maze[0])

        q = deque([(entrance[0], entrance[1], 0)])
        vis = set()

        while len(q) > 0:
            i, j, d = q.popleft()

            if (i, j) in vis:
                continue
            vis.add((i, j))

            if not (0 <= i < m and 0 <= j < n):
                if d > 1:
                    return d - 1
                continue

            if maze[i][j] == '+':
                continue

            for di, dj in directions:
                q.append((i + di, j + dj, d + 1))

        return -1
