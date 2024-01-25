import heapq


class Solution:

    def connectSticks(self, sticks: List[int]) -> int:
        result = 0

        q = []
        for v in sticks:
            heapq.heappush(q, v)

        while len(q) > 1:
            a = heapq.heappop(q)
            b = heapq.heappop(q)
            result += a + b
            heapq.heappush(q, a + b)

        return result
