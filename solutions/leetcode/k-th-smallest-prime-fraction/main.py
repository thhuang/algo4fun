class Solution:

    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        arr.sort()

        pq = []

        for i, v in enumerate(arr):
            if i == 0:
                continue
            heapq.heappush(pq, (1 / v, 0, i))

        for _ in range(k - 1):
            _, a, b = heapq.heappop(pq)
            a += 1
            if a < b:
                heapq.heappush(pq, (arr[a] / arr[b], a, b))

        _, a, b = heapq.heappop(pq)
        return [arr[a], arr[b]]
