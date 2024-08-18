class Solution:

    def nthUglyNumber(self, n: int) -> int:
        pq = []
        heapq.heappush(pq, 1)
        seen = set([1])

        result = None
        for _ in range(n):
            result = heapq.heappop(pq)
            for p in (2, 3, 5):
                v = p * result
                if v not in seen:
                    seen.add(v)
                    heapq.heappush(pq, v)

        return result
