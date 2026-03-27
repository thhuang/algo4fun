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


class Solution:

    def orangesRotting(self, grid: List[List[int]]) -> int:
        directions = ((0, 1), (0, -1), (1, 0), (-1, 0))
        m = len(grid)
        n = len(grid[0])

        q = []
        fresh = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    q.append((i, j))
                elif grid[i][j] == 1:
                    fresh += 1

        t = 0
        while q and fresh > 0:
            t += 1
            nq = []

            for i, j in q:
                for di, dj in directions:
                    ii = i + di
                    jj = j + dj
                    if 0 <= ii < m and 0 <= jj < n and grid[ii][jj] == 1:
                        grid[ii][jj] = 2
                        nq.append((ii, jj))
                        fresh -= 1

            q = nq

        return -1 if fresh > 0 else t
