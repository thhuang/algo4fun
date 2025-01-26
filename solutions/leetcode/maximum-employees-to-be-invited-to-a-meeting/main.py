class Solution:

    def maximumInvitations(self, favorite: List[int]) -> int:
        n = len(favorite)

        in_degree = [0] * n
        for u in range(n):
            in_degree[favorite[u]] += 1

        stack = []
        for u in range(n):
            if in_degree[u] == 0:
                stack.append(u)

        depth = [1] * n
        while len(stack) > 0:
            u = stack.pop()
            v = favorite[u]
            depth[v] = max(depth[v], depth[u] + 1)
            in_degree[v] -= 1
            if in_degree[v] == 0:
                stack.append(v)

        max_cycle = 0
        chain = 0

        for s in range(n):
            if in_degree[s] == 0:
                continue

            cycle = 0
            u = s
            while in_degree[u] != 0:
                in_degree[u] = 0
                cycle += 1
                u = favorite[u]

            max_cycle = max(max_cycle, cycle)
            if cycle == 2:
                chain += depth[u] + depth[favorite[u]]

        return max(max_cycle, chain)
