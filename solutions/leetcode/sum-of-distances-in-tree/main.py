class Solution:

    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        subtree_distance = [None] * n
        subtree_count = [None] * n

        def preprocess(u, p):
            nonlocal subtree_distance
            nonlocal subtree_count

            if u is None:
                return 0, 0

            dist, cnt = 0, 0
            for v in adj[u]:
                if v != p:
                    d, c = preprocess(v, u)
                    dist += d
                    cnt += c

            subtree_distance[u] = dist + cnt
            subtree_count[u] = cnt + 1

            return subtree_distance[u], subtree_count[u]

        preprocess(0, -1)

        result = [None] * n

        def process(u, p, p_dist, p_cnt):
            nonlocal result

            if u is None:
                return

            result[u] = subtree_distance[u] + p_dist + p_cnt

            for v in adj[u]:
                if v != p:
                    process(v, u, result[u] - subtree_distance[v] - subtree_count[v],
                            p_cnt + subtree_count[u] - subtree_count[v])

        process(0, -1, 0, 0)

        return result
