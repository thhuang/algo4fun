class Solution:
    directions = ((1, 0), (-1, 0), (0, 1), (0, -1))

    def trapRainWater(self, height_map: List[List[int]]) -> int:
        m = len(height_map)
        n = len(height_map[0])

        heights = []
        for i in range(m):
            heapq.heappush(heights, (height_map[i][0], i, 0))
            heapq.heappush(heights, (height_map[i][n - 1], i, n - 1))
        for j in range(n):
            heapq.heappush(heights, (height_map[0][j], 0, j))
            heapq.heappush(heights, (height_map[m - 1][j], m - 1, j))

        vis = set()
        result = 0

        while len(heights) > 0:
            h, i, j = heapq.heappop(heights)

            if (i, j) in vis:
                continue
            vis.add((i, j))

            result += h - height_map[i][j]

            for di, dj in self.directions:
                ii, jj = i + di, j + dj
                if not (0 <= ii < m and 0 <= jj < n):
                    continue
                heapq.heappush(heights, (max(h, height_map[ii][jj]), ii, jj))

        return result
