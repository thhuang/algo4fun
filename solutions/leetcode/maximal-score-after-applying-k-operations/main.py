class Solution:

    def maxKelements(self, nums: List[int], k: int) -> int:
        pq = [-v for v in nums]
        heapq.heapify(pq)

        result = 0

        for _ in range(k):
            v = -heapq.heappop(pq)
            result += v
            heapq.heappush(pq, -ceil(v / 3))

        return result
