class Solution:

    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int,
                          dst: int, k: int) -> int:
        adj = [[] for _ in range(n)]
        for a, b, p in flights:
            adj[a].append((b, p))

        pq = [(0, -1, src)]
        min_price = defaultdict(lambda: inf)

        while len(pq) > 0:
            p, s, u = heapq.heappop(pq)

            if u == dst: return p
            if s == k: continue
            if min_price[(u, s)] <= p: continue
            min_price[(u, s)] = p

            for v, dp in adj[u]:
                heapq.heappush(pq, (p + dp, s + 1, v))

        return -1
