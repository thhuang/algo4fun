class Solution:

    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:

        def check(r: int, c: int) -> bool:
            if set([grid[r + i][c + j] for i in range(3) for j in range(3)]) != {1, 2, 3, 4, 5, 6, 7, 8, 9}:
                return False

            s = sum([grid[r + i][c + i] for i in range(3)])
            if s != sum([grid[r + i][c + 2 - i] for i in range(3)]):
                return False
            for i in range(3):
                if s != sum([grid[r + i][c + j] for j in range(3)]):
                    return False
            for j in range(3):
                if s != sum([grid[r + i][c + j] for i in range(3)]):
                    return False

            return True

        m, n = len(grid), len(grid[0])
        result = 0
        for i in range(0, m - 2):
            for j in range(0, n - 2):
                if check(i, j):
                    result += 1

        return result
