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
