class Solution:

    def findMaxAverage(self, nums: List[int], k: int) -> float:
        result = -inf
        window = sum(nums[:k - 1])
        for r in range(k - 1, len(nums)):
            window += nums[r]
            result = max(result, window / k)
            window -= nums[r - k + 1]
        return result
