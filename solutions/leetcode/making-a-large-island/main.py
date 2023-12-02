class Solution:

    def largestIsland(self, grid: List[List[int]]) -> int:
        directions = ((0, 1), (0, -1), (1, 0), (-1, 0))

        m = len(grid)
        n = len(grid[0])

        vis = defaultdict(int)

        def dfs(i, j, k) -> int:
            if i < 0 or m <= i or j < 0 or n <= j or vis[(
                    i, j)] != 0 or grid[i][j] == 0:
                return 0
            vis[(i, j)] = k
            total = 1
            for di, dj in directions:
                total += dfs(i + di, j + dj, k)
            return total

        size = defaultdict(int)

        k = 1
        for i in range(m):
            for j in range(n):
                size[k] = dfs(i, j, k)
                k += 1

        result = max(1, max(size.values()))

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    continue

                connected = set()
                v = 1
                for di, dj in directions:
                    ii, jj = i + di, j + dj

                    if ii < 0 or m <= ii or jj < 0 or n <= jj:
                        continue

                    k = vis[(ii, jj)]
                    if k in connected:
                        continue
                    connected.add(k)
                    v += size[k]

                result = max(result, v)

        return result
