class Solution:

    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        projects = sorted(zip(capital, profits))

        result = w
        pq = []
        p = 0

        for _ in range(k):
            while p < len(projects) and projects[p][0] <= result:
                heapq.heappush(pq, -projects[p][1])
                p += 1
            if len(pq) == 0:
                break

            result -= heapq.heappop(pq)

        return result
