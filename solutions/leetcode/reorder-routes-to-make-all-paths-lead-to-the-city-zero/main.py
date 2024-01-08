class Solution:

    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]
        for e in connections:
            adj[e[1]].append((e[0], 0))
            adj[e[0]].append((e[1], 1))

        vis = [False for _ in range(n)]

        def dfs(u: int, c: int) -> int:
            if vis[u]:
                return 0
            vis[u] = True

            cost = c
            for e in adj[u]:
                cost += dfs(*e)

            return cost

        return dfs(0, 0)
