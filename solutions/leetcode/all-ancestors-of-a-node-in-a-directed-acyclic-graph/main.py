class Solution:

    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        adj = [[] for _ in range(n)]
        for a, b in edges:
            adj[b].append(a)

        ancestors = [set() for _ in range(n)]

        def dfs(u):
            nonlocal ancestors

            if len(ancestors[u]) > 0:
                return

            for v in adj[u]:
                dfs(v)
                ancestors[u] = ancestors[u] | ancestors[v] | {v}

        for u in range(n):
            dfs(u)

        return [sorted(v) for v in ancestors]
