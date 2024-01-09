class Solution:

    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        if candidates * 2 >= len(costs):
            return sum(sorted(costs)[:k])

        pq = []
        for i in range(candidates):
            heapq.heappush(pq, (costs[i], i))
            heapq.heappush(pq, (costs[-1 - i], len(costs) - 1 - i))

        result = 0

        l = candidates
        r = len(costs) - 1 - candidates
        while k > 0 and l <= r:
            v, i = heapq.heappop(pq)
            result += v
            if i < l:
                heapq.heappush(pq, (costs[l], l))
                l += 1
            else:
                heapq.heappush(pq, (costs[r], r))
                r -= 1
            k -= 1

        for i in range(k):
            v, _ = heapq.heappop(pq)
            result += v

        return result
