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


class Solution:

    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)

        parent = [i for i in range(n + 1)]
        rank = [0] * (n + 1)

        def find(x: int) -> int:
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]

        def unite(a: int, b: int) -> bool:
            pa, pb = find(a), find(b)
            if pa == pb:
                return False

            if rank[pa] < rank[pb]:
                pa, pb = pb, pa
            elif rank[pa] == rank[pb]:
                rank[pa] += 1

            parent[pb] = pa

            return True

        for a, b in edges:
            if not unite(a, b):
                return [a, b]

        return []
