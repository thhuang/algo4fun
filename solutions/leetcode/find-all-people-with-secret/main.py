class Solution:

    def findAllPeople(self, n: int, meetings: List[List[int]],
                      firstPerson: int) -> List[int]:
        adj = [[] for _ in range(n)]
        for u, v, t in meetings:
            adj[u].append((v, t))
            adj[v].append((u, t))

        vis = [inf] * n

        q = deque([(0, 0), (firstPerson, 0)])

        while len(q) > 0:
            u, t = q.popleft()

            if vis[u] <= t: continue
            vis[u] = t

            for v, tt in adj[u]:
                if tt < t: continue
                q.append((v, tt))

        return [i for i, t in enumerate(vis) if t < inf]
