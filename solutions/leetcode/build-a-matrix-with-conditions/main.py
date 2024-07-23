class Solution:

    def buildMatrix(self, k: int, row_conditions: List[List[int]], col_conditions: List[List[int]]) -> List[List[int]]:

        def getOrder(conditions):
            adj = [[] for _ in range(k)]
            for u, v in conditions:
                adj[u - 1].append(v - 1)

            state = [0] * k
            rdag = []

            def dfs(u):
                if state[u] == 1:
                    return False
                if state[u] == 2:
                    return True
                state[u] = 1

                for v in adj[u]:
                    if not dfs(v):
                        return False

                state[u] = 2
                rdag.append(u)
                return True

            for i in range(k):
                if not dfs(i):
                    return None

            for i in range(k):
                if state[i] == 0:
                    rdag.append(i)

            return {u: i for i, u in enumerate(rdag[::-1])}

        row_order = getOrder(row_conditions)
        col_order = getOrder(col_conditions)
        if row_order is None or col_order is None:
            return []

        result = [[0 for _ in range(k)] for _ in range(k)]
        for u in range(k):
            i = row_order[u]
            j = col_order[u]
            result[i][j] = u + 1

        return result
