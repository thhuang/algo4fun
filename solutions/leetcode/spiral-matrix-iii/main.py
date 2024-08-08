class Solution:

    def spiralMatrixIII(self, rows: int, cols: int, r_start: int, c_start: int) -> List[List[int]]:
        directions = ((0, 1), (1, 0), (0, -1), (-1, 0))

        i, j = r_start, c_start
        d = 0

        result = []
        for k in range(max(rows, cols) * 4):
            for _ in range(k // 2 + 1):
                if 0 <= i < rows and 0 <= j < cols:
                    result.append((i, j))
                i += directions[d][0]
                j += directions[d][1]
                if len(result) == rows * cols:
                    return result
            d = (d + 1) % 4

        return result
