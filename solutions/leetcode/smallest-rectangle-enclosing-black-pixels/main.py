class Solution:

    def minArea(self, image: List[List[str]], x: int, y: int) -> int:
        directions = ((1, 0), (-1, 0), (0, 1), (0, -1))

        m, n = len(image), len(image[0])

        row_min, row_max = m, 0
        col_min, col_max = n, 0

        vis = set()

        q = deque([(x, y)])
        while len(q) > 0:
            i, j = q.popleft()

            if (i, j) in vis:
                continue
            vis.add((i, j))

            row_min = min(row_min, i)
            row_max = max(row_max, i)
            col_min = min(col_min, j)
            col_max = max(col_max, j)

            for di, dj in directions:
                ii, jj = i + di, j + dj
                if 0 <= ii < m and 0 <= jj < n and image[ii][jj] == '1':
                    q.append((ii, jj))

        return (row_max - row_min + 1) * (col_max - col_min + 1)
