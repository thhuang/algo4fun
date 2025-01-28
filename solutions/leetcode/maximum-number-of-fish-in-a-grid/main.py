class Solution:
    DIRECTIONS = ((0, 1), (1, 0), (0, -1), (-1, 0))

    def findMaxFish(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        result = 0

        for r in range(m):
            for c in range(n):
                if grid[r][c] == 0:
                    continue

                acc = 0
                q = deque([(r, c)])

                while len(q) > 0:
                    i, j = q.popleft()
                    if not 0 <= i < m or not 0 <= j < n or grid[i][j] == 0:
                        continue

                    acc += grid[i][j]
                    grid[i][j] = 0

                    for di, dj in self.DIRECTIONS:
                        q.append((i + di, j + dj))

                result = max(result, acc)

        return result
