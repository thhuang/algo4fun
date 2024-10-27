class Solution:

    def countSquares(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0])

        result = 0

        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

        for i in range(m)[::-1]:
            for j in range(n)[::-1]:
                if matrix[i][j] == 0:
                    continue
                dp[i][j] = min((dp[i][j + 1], dp[i + 1][j], dp[i + 1][j + 1])) + 1
                result += dp[i][j]

        return result
