class Solution:

    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        m = len(land)
        n = len(land[0])

        result = []

        def search(r1, c1):
            r2 = m - 1
            for i in range(r1 + 1, m):
                if land[i][c1] == 0:
                    r2 = i - 1
                    break

            c2 = n - 1
            for j in range(c1 + 1, n):
                if land[r1][j] == 0:
                    c2 = j - 1
                    break

            return [r1, c1, r2, c2]

        for i in range(m):
            for j in range(n):
                if land[i][j] == 0:
                    continue
                if 0 < i and land[i - 1][j] == 1:
                    continue
                if 0 < j and land[i][j - 1] == 1:
                    continue
                result.append(search(i, j))

        return result
