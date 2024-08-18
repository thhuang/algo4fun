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


class Solution:

    def nthUglyNumber(self, n: int) -> int:
        dp = [0] * n
        p2, p3, p5 = 0, 0, 0
        dp[0] = 1
        for i in range(1, n):
            v = min(dp[p2] * 2, dp[p3] * 3, dp[p5] * 5)
            dp[i] = v
            if v == dp[p2] * 2:
                p2 += 1
            if v == dp[p3] * 3:
                p3 += 1
            if v == dp[p5] * 5:
                p5 += 1
        return dp[-1]
