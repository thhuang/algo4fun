class Solution:

    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        dist = [inf] * (n + 1)

        adj = [[] for _ in range(n + 1)]
        for u, v, w in times:
            adj[u].append((v, w))

        h = [(0, k)]

        while len(h) > 0:
            t, u = heappop(h)

            if dist[u] <= t:
                continue
            dist[u] = t

            for v, w in adj[u]:
                heappush(h, (t + w, v))

        result = max(dist[1:])
        return -1 if result == inf else result
