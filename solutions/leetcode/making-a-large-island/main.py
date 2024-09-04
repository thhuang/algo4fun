class Solution:

    def largestIsland(self, grid: List[List[int]]) -> int:
        directions = ((0, 1), (0, -1), (1, 0), (-1, 0))

        m = len(grid)
        n = len(grid[0])

        vis = defaultdict(int)

        def dfs(i, j, k) -> int:
            if i < 0 or m <= i or j < 0 or n <= j or vis[(i, j)] != 0 or grid[i][j] == 0:
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


class Solution:

    def largestIsland(self, grid: List[List[int]]) -> int:
        directions = ((0, 1), (0, -1), (1, 0), (-1, 0))

        m, n = len(grid), len(grid[0])

        vis = [[0 for _ in range(n)] for _ in range(m)]

        def dfs(i: int, j: int, island: int) -> int:
            if i < 0 or m <= i or j < 0 or n <= j or vis[i][j] != 0 or grid[i][j] == 0:
                return 0
            vis[i][j] = island
            sz = 1
            for di, dj in directions:
                sz += dfs(i + di, j + dj, island)
            return sz

        island_size = {0: 0}

        k = 1
        for i in range(m):
            for j in range(n):
                if vis[i][j] == 0 and grid[i][j] == 1:
                    island_size[k] = dfs(i, j, k)
                    k += 1

        result = max(1, max(island_size.values()))
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    continue

                neighbors = set()
                sz = 1
                for di, dj in directions:
                    ii, jj = i + di, j + dj
                    if 0 <= ii < m and 0 <= jj < n:
                        neighbors.add(vis[ii][jj])

                sz = 1
                for k in neighbors:
                    sz += island_size[k]

                result = max(result, sz)

        return result


class Solution:

    def largestIsland(self, grid: List[List[int]]) -> int:
        directions = ((0, 1), (0, -1), (1, 0), (-1, 0))

        m, n = len(grid), len(grid[0])

        vis = [[0 for _ in range(n)] for _ in range(m)]

        def dfs(i: int, j: int, island: int) -> int:
            if i < 0 or m <= i or j < 0 or n <= j or vis[i][j] != 0 or grid[i][j] == 0:
                return 0
            vis[i][j] = island
            sz = 1
            for di, dj in directions:
                sz += dfs(i + di, j + dj, island)
            return sz

        island_size = {0: 0}

        k = 1
        for i in range(m):
            for j in range(n):
                if vis[i][j] == 0 and grid[i][j] == 1:
                    island_size[k] = dfs(i, j, k)
                    k += 1

        result = 1
        for i in range(m):
            for j in range(n):
                neighbors = set()
                sz = 1
                for di, dj in directions:
                    ii, jj = i + di, j + dj
                    if 0 <= ii < m and 0 <= jj < n:
                        neighbors.add(vis[ii][jj])

                sz = 1 if grid[i][j] == 0 else 0
                for k in neighbors:
                    sz += island_size[k]

                result = max(result, sz)

        return result
