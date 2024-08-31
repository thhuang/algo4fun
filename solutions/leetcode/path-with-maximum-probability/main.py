class Solution:

    def maxProbability(self, n: int, edges: List[List[int]], succ_prob: List[float], start_node: int,
                       end_node: int) -> float:
        adj = [[] for _ in range(n)]
        for i, (a, b) in enumerate(edges):
            adj[a].append((b, succ_prob[i]))
            adj[b].append((a, succ_prob[i]))

        vis = set()
        pq = [(-1, start_node)]

        while len(pq) > 0:
            neg_prob, u = heapq.heappop(pq)

            if u in vis:
                continue
            vis.add(u)

            if u == end_node:
                return -neg_prob

            for v, p in adj[u]:
                if v in vis:
                    continue
                heapq.heappush(pq, (neg_prob * p, v))

        return 0


class Solution:

    def maxProbability(self, n: int, edges: List[List[int]], succ_prob: List[float], start_node: int,
                       end_node: int) -> float:
        adj = [[] for _ in range(n)]
        for i, (a, b) in enumerate(edges):
            adj[a].append((b, succ_prob[i]))
            adj[b].append((a, succ_prob[i]))

        vis = [False] * n
        pq = [(-1, start_node)]

        while len(pq) > 0:
            nprob, u = heapq.heappop(pq)

            if u == end_node:
                return -nprob

            if vis[u]:
                continue
            vis[u] = True

            for v, p in adj[u]:
                heapq.heappush(pq, (nprob * p, v))

        return 0
