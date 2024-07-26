class Solution:

    def findTheCity(self, n: int, edges: List[List[int]], distance_threshold: int) -> int:
        dist_mat = [[inf for _ in range(n)] for _ in range(n)]
        for u in range(n):
            dist_mat[u][u] = 0
        for u, v, d in edges:
            dist_mat[u][v] = d
            dist_mat[v][u] = d

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    dist_mat[i][j] = min(dist_mat[i][j], dist_mat[i][k] + dist_mat[k][j])

        result = -1
        neighbors = inf
        for u in range(n):
            cnt = 0
            for v in range(n):
                if dist_mat[u][v] <= distance_threshold:
                    cnt += 1
            if cnt <= neighbors:
                neighbors = cnt
                result = u

        return result
