class Solution:

    def maxMoves(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        result = 0
        q = deque([(i, 0, 0) for i in range(m)])  # (i, j, moves)

        vis = set()

        while len(q) > 0 and result < n - 1:
            i, j, mov = q.popleft()

            jj = j + 1
            mmov = mov + 1
            for di in (-1, 0, 1):
                ii = i + di
                if 0 <= ii < m and grid[i][j] < grid[ii][jj]:
                    result = max(result, mmov)
                    if (ii, jj) in vis:
                        continue
                    vis.add((ii, jj))
                    q.append((ii, jj, mmov))

        return result
