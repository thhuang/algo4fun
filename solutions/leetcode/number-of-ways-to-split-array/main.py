class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        s = sum(nums)
        left = 0
        result = 0
        for v in nums[: len(nums) - 1]:
            left += v
            right = s - left
            if left >= right:
                result += 1
        return result
