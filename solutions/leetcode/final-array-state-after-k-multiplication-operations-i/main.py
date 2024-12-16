class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        pq = [(v, i) for i, v in enumerate(nums)]
        heapq.heapify(pq)
        for _ in range(k):
            _, i = heapq.heappop(pq)
            nums[i] *= multiplier
            heapq.heappush(pq, (nums[i], i))
        return nums
