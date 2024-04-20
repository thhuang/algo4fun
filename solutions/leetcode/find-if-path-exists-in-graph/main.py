class Solution:

    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        vis = set()

        q = deque([source])
        while len(q) > 0:
            u = q.popleft()
            if u == destination:
                return True
            if u in vis:
                continue
            vis.add(u)
            for v in adj[u]:
                q.append(v)

        return False
