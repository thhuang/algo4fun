class Solution:
    directions = ((0, 1), (0, -1), (1, 0), (-1, 0))

    def minCost(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        vis = {}
        stack = [(0, 0)]

        for c in range(m + n):

            new_vis = []
            while len(stack) > 0:
                i, j = stack.pop()
                if not 0 <= i < m or not 0 <= j < n or (i, j) in vis:
                    continue
                if i == m - 1 and j == n - 1:
                    return c

                vis[(i, j)] = c
                new_vis.append((i, j))

                di, dj = self.directions[grid[i][j] - 1]
                stack.append((i + di, j + dj))

            for i, j in new_vis:
                for di, dj in self.directions:
                    stack.append((i + di, j + dj))

        return m + n - 1
