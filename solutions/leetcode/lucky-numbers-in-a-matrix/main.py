class Solution:

    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])

        row_min = [inf] * m
        col_max = [-inf] * n

        for i in range(m):
            for j in range(n):
                row_min[i] = min(row_min[i], matrix[i][j])
                col_max[j] = max(col_max[j], matrix[i][j])

        result = []

        for i in range(m):
            for j in range(n):
                if row_min[i] == col_max[j]:
                    result.append(matrix[i][j])

        return result
