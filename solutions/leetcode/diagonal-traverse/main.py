class Solution:

    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        directions = ((-1, 1), (1, -1))
        m, n = len(mat), len(mat[0])
        result = []

        i, j = 0, 0
        d = 0
        for _ in range(m * n):
            result.append(mat[i][j])

            ii = i + directions[d][0]
            jj = j + directions[d][1]
            if 0 <= ii < m and 0 <= jj < n:
                i, j = ii, jj
                continue

            d = (d + 1) % 2
            if d == 1:
                ii = i
                jj = j + 1
                if 0 <= ii < m and 0 <= jj < n:
                    i, j = ii, jj
                else:
                    i, j = i + 1, j

            else:  # d == 0
                ii = i + 1
                jj = j
                if 0 <= ii < m and 0 <= jj < n:
                    i, j = ii, jj
                else:
                    i, j = i, j + 1

        return result
