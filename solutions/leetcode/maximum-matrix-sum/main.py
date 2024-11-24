class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        mn = abs(matrix[0][0])
        result = 0
        is_even = True

        for row in matrix:
            for v in row:
                if v < 0:
                    is_even = not is_even
                result += abs(v)
                mn = min(mn, abs(v))

        return result if is_even else result - mn * 2
