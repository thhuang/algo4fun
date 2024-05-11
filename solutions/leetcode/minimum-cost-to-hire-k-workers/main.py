class Solution:

    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        wq_q = sorted([(wage[i] / q, q) for i, q in enumerate(quality)])

        highest_q = []
        total_q = 0

        result = inf

        for wq, q in wq_q:
            total_q += q
            heapq.heappush(highest_q, -q)
            k -= 1

            if k < 0:
                total_q += heapq.heappop(highest_q)
                k += 1

            if k == 0:
                result = min(result, wq * total_q)

        return result
