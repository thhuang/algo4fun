class Solution:

    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        for arr in nums:
            arr.sort()

        mx = -float("inf")

        pq = []
        for arr in nums:
            mx = max(mx, arr[0])
            heapq.heappush(pq, (arr[0], arr, 0))

        min_diff = float("inf")
        result = []

        while True:
            mn, arr, i = heapq.heappop(pq)

            if mx - mn < min_diff:
                min_diff = mx - mn
                result = [mn, mx]

            i += 1
            if i == len(arr):
                break

            mx = max(mx, arr[i])
            heapq.heappush(pq, (arr[i], arr, i))

        return result
