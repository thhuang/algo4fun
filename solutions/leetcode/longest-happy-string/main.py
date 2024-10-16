class Solution:

    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        pq = []

        heapq.heappush(pq, (-a, "a"))
        heapq.heappush(pq, (-b, "b"))
        heapq.heappush(pq, (-c, "c"))

        s = []

        while pq[0][0] != 0:
            cnt, ch = heapq.heappop(pq)
            cnt = -cnt

            if len(s) >= 2 and s[-1] == s[-2] == ch:
                if pq[0][0] == 0:
                    break
                cnt, ch = heapq.heapreplace(pq, (-cnt, ch))
                cnt = -cnt

            cnt -= 1
            s.append(ch)
            heapq.heappush(pq, (-cnt, ch))

        return "".join(s)
