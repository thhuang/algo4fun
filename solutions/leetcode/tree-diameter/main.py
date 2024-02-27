class Solution:

    def treeDiameter(self, edges: List[List[int]]) -> int:
        adj = defaultdict(lambda: [])
        for a, b in edges:
            adj[a].append(b)
            adj[b].append(a)

        def bfs(src):
            dist = -1
            q = deque([(src, -1)])

            dst = src
            while len(q) > 0:
                dist += 1
                n = len(q)

                for _ in range(n):
                    u, p = q.popleft()

                    dst = u
                    for v in adj[u]:
                        if v != p:
                            q.append((v, u))

            return dst, dist

        src, _ = bfs(0)
        _, result = bfs(src)

        return result
