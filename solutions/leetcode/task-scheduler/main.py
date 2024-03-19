class Solution:

    def leastInterval(self, tasks: List[str], n: int) -> int:
        pq = []  # (negative remain count, task)
        for task, cnt in Counter(tasks).items():
            heapq.heappush(pq, (-cnt, task))

        cooling = []  # (time, negative remain count, task)

        t = 0

        while len(pq) > 0 or len(cooling) > 0:
            while len(cooling) > 0 and cooling[0][0] < t:
                _, neg_cnt, task = heapq.heappop(cooling)
                heapq.heappush(pq, (neg_cnt, task))

            if len(pq) == 0:
                t = cooling[0][0] + 1
                continue

            neg_cnt, task = heapq.heappop(pq)
            neg_cnt += 1

            if neg_cnt < 0:
                heapq.heappush(cooling, (t + n, neg_cnt, task))

            t += 1

        return t
