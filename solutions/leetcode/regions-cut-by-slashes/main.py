class DisjointSet:

    def __init__(self, n):
        self.group = [i for i in range(n)]
        self.rank = [0] * n

    def find(self, k):
        if self.group[k] == k:
            return k
        self.group[k] = self.find(self.group[k])
        return self.group[k]

    def unite(self, a, b):
        ga = self.find(a)
        gb = self.find(b)
        if ga == gb:
            return

        if self.rank[ga] < self.rank[gb]:
            self.group[ga] = gb
        elif self.rank[gb] < self.rank[ga]:
            self.group[gb] = ga
        else:
            self.group[gb] = ga
            self.rank[ga] += 1

    def groups(self):
        n = len(self.group)
        return len(set([self.find(i) for i in range(n)]))


class Solution:

    def regionsBySlashes(self, grid: List[str]) -> int:
        m, n = len(grid), len(grid[0])

        ds = DisjointSet(4 * m * n)

        def convert(i, j, k):
            return (i * n + j) * 4 + k

        for i in range(m):
            for j in range(n):
                if i > 0:
                    ds.unite(convert(i, j, 0), convert(i - 1, j, 2))
                if j > 0:
                    ds.unite(convert(i, j, 1), convert(i, j - 1, 3))
                if grid[i][j] == "/":
                    ds.unite(convert(i, j, 0), convert(i, j, 1))
                    ds.unite(convert(i, j, 2), convert(i, j, 3))
                elif grid[i][j] == "\\":
                    ds.unite(convert(i, j, 1), convert(i, j, 2))
                    ds.unite(convert(i, j, 3), convert(i, j, 0))
                else:
                    ds.unite(convert(i, j, 0), convert(i, j, 1))
                    ds.unite(convert(i, j, 1), convert(i, j, 2))
                    ds.unite(convert(i, j, 2), convert(i, j, 3))

        return ds.groups()


class Solution:

    def regionsBySlashes(self, grid: List[str]) -> int:
        m, n = len(grid), len(grid[0])

        group = [i for i in range(m * n * 4)]
        rank = [0] * (m * n * 4)

        def find(k: int) -> int:
            if group[k] == k:
                return k
            group[k] = find(group[k])
            return group[k]

        def unite(a: int, b: int):
            ga = find(a)
            gb = find(b)
            if ga == gb:
                return
            if rank[ga] < rank[gb]:
                group[ga] = gb
            elif rank[gb] < rank[ga]:
                group[gb] = ga
            else:
                group[gb] = ga
                rank[ga] += 1

        def idx(i: int, j: int, k: int) -> int:
            return (i * n + j) * 4 + k

        for i in range(m):
            for j in range(n):
                if i > 0:
                    unite(idx(i, j, 0), idx(i - 1, j, 2))
                if j > 0:
                    unite(idx(i, j, 3), idx(i, j - 1, 1))
                if grid[i][j] == "/":
                    unite(idx(i, j, 0), idx(i, j, 3))
                    unite(idx(i, j, 1), idx(i, j, 2))
                elif grid[i][j] == "\\":
                    unite(idx(i, j, 0), idx(i, j, 1))
                    unite(idx(i, j, 2), idx(i, j, 3))
                else:  # grid[i][j] == " ":
                    unite(idx(i, j, 0), idx(i, j, 1))
                    unite(idx(i, j, 1), idx(i, j, 2))
                    unite(idx(i, j, 2), idx(i, j, 3))

        return len(set([find(idx(i, j, k)) for i in range(m) for j in range(n) for k in range(4)]))
