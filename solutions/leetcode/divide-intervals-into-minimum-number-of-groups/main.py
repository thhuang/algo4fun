class Solution:

    def minGroups(self, intervals: List[List[int]]) -> int:
        pq = [0]

        for l, r in sorted(intervals):
            if pq[0] < l:
                heapq.heappop(pq)
            heapq.heappush(pq, r)

        return len(pq)
