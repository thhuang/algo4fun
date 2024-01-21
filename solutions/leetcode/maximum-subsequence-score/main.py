import heapq


class Solution:

    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        n = len(nums1)

        idx = [i for i in range(n)]
        idx.sort(key=lambda i: nums2[i], reverse=True)

        result = 0

        pq = []
        window = 0

        for r in range(n):
            l = r - k + 1
            window += nums1[idx[r]]

            heapq.heappush(pq, nums1[idx[r]])

            if l < 0:
                continue

            result = max(result, nums2[idx[r]] * window)

            window -= heapq.heappop(pq)

        return result
