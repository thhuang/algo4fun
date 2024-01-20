class Solution:

    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)

        rank = [0 for _ in range(n)]
        group = [i for i in range(n)]

        def find(u):
            if group[u] == u:
                return u
            group[u] = find(group[u])
            return group[u]

        def unite(a, b):
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

        for i, row in enumerate(isConnected):
            for j, v in enumerate(row):
                if v == 1:
                    unite(i, j)

        provinces = set()
        for i in range(n):
            provinces.add(find(i))

        return len(provinces)
