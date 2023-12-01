class Solution:

    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)

        group = [i for i in range(n)]
        rank = [0 for i in range(n)]

        def find(u) -> int:
            if group[u] == u:
                return u
            group[u] = find(group[u])
            return group[u]

        def unite(u, v) -> bool:
            gu = find(u)
            gv = find(v)
            if gu == gv:
                return False
            if rank[gu] < rank[gv]:
                group[gu] = gv
            elif rank[gv] < rank[gu]:
                group[gv] = gu
            else:
                group[gu] = gv
                rank[gv] += 1
            return True

        for e in edges:
            u = e[0] - 1
            v = e[1] - 1
            if not unite(u, v):
                return e

        return None
