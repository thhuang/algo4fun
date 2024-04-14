class Solution:

    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        m = len(matrix)
        n = len(matrix[0])

        left = [0] * n
        right = [n - 1] * n
        height = [0] * n

        result = 0

        for i in range(m):
            curr_left = 0
            for j in range(n):
                if matrix[i][j] == "0":
                    curr_left = j + 1
                    left[j] = 0
                else:
                    left[j] = max(left[j], curr_left)

            curr_right = n - 1
            for j in reversed(range(n)):
                if matrix[i][j] == "0":
                    curr_right = j - 1
                    right[j] = n - 1
                else:
                    right[j] = min(right[j], curr_right)

            for j in range(n):
                if matrix[i][j] == "0":
                    height[j] = 0
                else:
                    height[j] += 1

            for j in range(n):
                if matrix[i][j] == "1":
                    result = max(result, (right[j] - left[j] + 1) * height[j])

        return result
