class Solution:

    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        pq = [1]
        exists = set(pq)

        result = 0
        for _ in range(n):
            result = heapq.heappop(pq)
            for p in primes:
                v = result * p
                if v not in exists:
                    heapq.heappush(pq, v)
                    exists.add(v)

        return result
