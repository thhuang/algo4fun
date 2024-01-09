class Solution:

    def calcEquation(self, equations: List[List[str]], values: List[float],
                     queries: List[List[str]]) -> List[float]:
        adj = dict()

        for i in range(len(equations)):
            a, b = equations[i]

            if a not in adj:
                adj[a] = dict()
            adj[a][b] = values[i]

            if b not in adj:
                adj[b] = dict()
            adj[b][a] = 1 / values[i]

        def dfs(s: int, t: int) -> int:
            nonlocal vis

            if s not in adj:
                return -1
            if s == t:
                return 1
            if t in adj[s]:
                return adj[s][t]

            if vis[s]:
                return -1
            vis[s] = True

            for k, v in adj[s].items():
                r = dfs(k, t)
                if r != -1:
                    adj[k][t] = r
                    return v * r

            return -1

        result = []
        for a, b in queries:
            vis = defaultdict(bool)
            result.append(dfs(a, b))

        return result


class Solution:

    def calcEquation(self, equations: List[List[str]], values: List[float],
                     queries: List[List[str]]) -> List[float]:
        adj = dict()
        for i in range(len(equations)):
            a, b = equations[i]
            v = values[i]

            if a not in adj:
                adj[a] = dict()
            adj[a][b] = v

            if b not in adj:
                adj[b] = dict()
            adj[b][a] = 1 / v

        vis = set()

        def dfs(u: int) -> None:
            if u not in adj:
                return
            if u in vis:
                return
            vis.add(u)

            for v, v_val in tuple(adj[u].items()):
                dfs(v)
                for w, w_val in adj[v].items():
                    adj[u][w] = v_val * w_val
                    adj[w][u] = 1 / adj[u][w]

        result = []
        for a, b in queries:
            dfs(a)
            if a not in adj or b not in adj[a]:
                result.append(-1)
            else:
                result.append(adj[a][b])

        return result
