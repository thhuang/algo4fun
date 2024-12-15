class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extra_students: int) -> float:
        get_delta = lambda p, t: ((p + 1) / (t + 1)) - (p / t)

        pq = []

        for p, t in classes:
            heapq.heappush(pq, (-get_delta(p, t), p, t))

        for _ in range(extra_students):
            _, p, t = heapq.heappop(pq)
            p += 1
            t += 1
            heapq.heappush(pq, (-get_delta(p, t), p, t))

        result = 0
        for _, p, t in pq:
            result += p / t
        result /= len(pq)

        return result
