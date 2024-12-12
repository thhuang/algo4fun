class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        pq = []
        for v in gifts:
            heapq.heappush(pq, -v)
        for _ in range(k):
            v = -heapq.heappop(pq)
            heapq.heappush(pq, -floor(sqrt(v)))

        result = 0
        while len(pq) > 0:
            result += -heapq.heappop(pq)

        return result
