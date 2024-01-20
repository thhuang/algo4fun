class Solution:

    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        dp = matrix[0]
        for i in range(1, m):
            dp_new = dp.copy()
            for j in range(n):
                if j - 1 >= 0:
                    dp_new[j] = min(dp_new[j], dp[j - 1])
                if j + 1 < n:
                    dp_new[j] = min(dp_new[j], dp[j + 1])
                dp_new[j] += matrix[i][j]
            dp = dp_new
        return min(dp)
