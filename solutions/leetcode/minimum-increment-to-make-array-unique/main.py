class Solution:

    def minIncrementForUnique(self, nums: List[int]) -> int:
        nums.sort()

        result = 0

        for i in range(1, len(nums)):
            if nums[i - 1] < nums[i]:
                continue
            diff = nums[i - 1] + 1 - nums[i]
            nums[i] += diff
            result += diff

        return result
