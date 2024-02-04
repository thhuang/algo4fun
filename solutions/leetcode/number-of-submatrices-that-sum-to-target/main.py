class Solution:

    def numSubmatrixSumTarget(self, matrix: List[List[int]],
                              target: int) -> int:
        m = len(matrix)
        n = len(matrix[0])

        suffix = defaultdict(int)
        for i in reversed(range(m)):
            s = 0
            for j in reversed(range(n)):
                s += matrix[i][j]
                suffix[(i, j)] = suffix[(i + 1, j)] + s

        result = 0
        for l in range(n):
            for r in range(l, n):
                prefix_sum = defaultdict(int)
                prefix_sum[0] = 1
                for i in reversed(range(m)):
                    v = suffix[(i, l)] - suffix[(i, r + 1)]
                    result += prefix_sum[v - target]
                    prefix_sum[v] += 1

        return result
