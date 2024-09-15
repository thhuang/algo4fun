class Solution:

    def modifiedGraphEdges(self, n: int, edges: List[List[int]], source: int, destination: int,
                           target: int) -> List[List[int]]:
        inf = 10**9
        adj = defaultdict(lambda: defaultdict(int))
        todo = []
        for u, v, w in edges:
            if w == -1:
                todo.append((u, v))
                adj[u][v] = inf
                adj[v][u] = inf
            else:
                adj[u][v] = w
                adj[v][u] = w

        def dijkstra(adj):
            best = [inf] * n
            vis = [False] * n

            pq = [(0, source)]
            best[source] = 0

            while len(pq) > 0:
                d, u = heapq.heappop(pq)

                if u == destination:
                    return d

                if vis[u]:
                    continue
                vis[u] = True

                for v, w in adj[u].items():
                    if d + w < best[v] and d + w <= target and not vis[v]:
                        best[v] = d + w
                        heapq.heappush(pq, (d + w, v))

            return inf

        def convertToEdges(adj):
            edges = []
            for u in adj.keys():
                for v in adj[u]:
                    if u < v:
                        edges.append((u, v, adj[u][v]))
            return edges

        match dijkstra(adj):
            case d if d < target:
                return []
            case d if d == target:
                return convertToEdges(adj)

        for u, v in todo:
            adj[u][v] = 1
            adj[v][u] = 1

            match dijkstra(adj):
                case d if d == target:
                    return convertToEdges(adj)
                case d if d < target:
                    delta = target - d

                    adj[u][v] += delta
                    adj[v][u] += delta
                    return convertToEdges(adj)

        return []
