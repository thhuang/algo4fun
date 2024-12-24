class Solution:
    def minimumDiameterAfterMerge(
        self, edges1: List[List[int]], edges2: List[List[int]]
    ) -> int:
        adj1 = self.getAdj(edges1)
        adj2 = self.getAdj(edges2)

        d1 = self.getDiameterPath(adj1)
        d2 = self.getDiameterPath(adj2)
        d3 = (d1 + 1) // 2 + (d2 + 1) // 2 + 1

        return max(d1, d2, d3)

    def getAdj(self, edges: List[List[int]]) -> List[List[int]]:
        n = len(edges) + 1
        adj = [[] for _ in range(n)]
        for a, b in edges:
            adj[a].append(b)
            adj[b].append(a)
        return adj

    def farestNode(self, adj: List[List[int]], s: int) -> Tuple[int, int]:
        t = s
        length = 0
        q = deque([(s, 0)])
        vis = set()

        while len(q) > 0:
            u, length = q.popleft()
            vis.add(u)
            for v in adj[u]:
                if v in vis:
                    continue
                q.append((v, length + 1))
                t = v

        return t, length

    def getDiameterPath(self, adj: List[List[int]]) -> List[int]:
        a, _ = self.farestNode(adj, 0)
        b, diameter = self.farestNode(adj, a)
        return diameter
