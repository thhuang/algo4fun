class Solution:

    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        adj = [[] for i in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        longest_path = []
        curr = []

        def dfs(u, p):
            nonlocal longest_path
            nonlocal curr

            curr.append(u)

            if len(curr) > len(longest_path):
                longest_path[:] = curr

            for v in adj[u]:
                if v != p:
                    dfs(v, u)

            curr.pop()

        dfs(0, -1)
        a = longest_path[-1]

        longest_path = []
        curr = []

        dfs(a, -1)

        m = len(longest_path)
        if m % 2 == 1:
            return [longest_path[m // 2]]
        return [longest_path[m // 2 - 1], longest_path[m // 2]]
