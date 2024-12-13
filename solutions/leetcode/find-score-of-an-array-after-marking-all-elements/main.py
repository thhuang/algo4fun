class Solution:
    def findScore(self, nums: List[int]) -> int:
        marked = [False] * len(nums)

        pq = []
        for i, v in enumerate(nums):
            heapq.heappush(pq, (v, i))

        result = 0
        n = len(nums)

        while n > 0:
            v, i = heapq.heappop(pq)
            if marked[i]:
                continue

            result += v

            for j in range(i - 1, i + 2):
                if 0 <= j < len(marked) and not marked[j]:
                    marked[j] = True
                    n -= 1

        return result
