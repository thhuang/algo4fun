class Solution:

    def canFinish(self, numCourses: int,
                  prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        for v, u in prerequisites:
            adj[u].append(v)

        # 0: not processed yet
        # 1: processing
        # 2: processed
        visited = [0] * numCourses

        def dfs(u: int) -> bool:
            if visited[u] == 1:
                return False
            if visited[u] == 2:
                return True

            visited[u] = 1

            for v in adj[u]:
                if not dfs(v):
                    return False

            visited[u] = 2

            return True

        for u in range(numCourses):
            if not dfs(u):
                return False

        return True


class Solution:

    def canFinish(self, numCourses: int,
                  prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        indeg = [0 for _ in range(numCourses)]

        for v, u in prerequisites:
            adj[u].append(v)
            indeg[v] += 1

        q = deque([u for u, deg in enumerate(indeg) if deg == 0])
        processed = 0

        while len(q) > 0:
            u = q.popleft()

            processed += 1

            for v in adj[u]:
                indeg[v] -= 1
                if indeg[v] == 0:
                    q.append(v)

        return processed == numCourses
