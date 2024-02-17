class Solution:

    def furthestBuilding(self, heights: List[int], bricks: int,
                         ladders: int) -> int:
        n = len(heights)
        pq = []

        for i in range(1, n):
            dh = heights[i] - heights[i - 1]
            if dh <= 0:
                continue

            heapq.heappush(pq, dh)
            if len(pq) <= ladders:
                continue

            bricks -= heapq.heappop(pq)

            if bricks < 0:
                return i - 1

        return n - 1
