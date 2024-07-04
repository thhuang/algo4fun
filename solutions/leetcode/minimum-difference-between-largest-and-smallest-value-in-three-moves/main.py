class Solution:

    def minDifference(self, nums: List[int]) -> int:
        if len(nums) <= 4:
            return 0

        nums.sort()

        result = inf
        for i in range(4):
            result = min(result, nums[i + len(nums) - 4] - nums[i])

        return result
