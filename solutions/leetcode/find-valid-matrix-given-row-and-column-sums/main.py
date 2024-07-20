class Solution:

    def restoreMatrix(self, row_sum: List[int], col_sum: List[int]) -> List[List[int]]:
        m, n = len(row_sum), len(col_sum)

        result = [[0 for _ in range(n)] for _ in range(m)]

        curr_row_sum = [0] * m
        curr_col_sum = [0] * n

        for i in range(m):
            for j in range(n):
                result[i][j] = min(row_sum[i] - curr_row_sum[i], col_sum[j] - curr_col_sum[j])
                curr_row_sum[i] += result[i][j]
                curr_col_sum[j] += result[i][j]

        return result
