class Solution:

    def findOrder(self, numCourses: int,
                  prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        for v, u in prerequisites:
            adj[u].append(v)

        # 0: unprocessed
        # 1: processing
        # 2: processed
        visited = [0] * numCourses

        rresult = []

        def dfs(u: int) -> bool:
            if visited[u] == 2:
                return True
            if visited[u] == 1:
                return False

            visited[u] = 1

            for v in adj[u]:
                if not dfs(v):
                    return False

            rresult.append(u)
            visited[u] = 2

            return True

        for u in range(numCourses):
            if not dfs(u):
                return []

        return rresult[::-1]
