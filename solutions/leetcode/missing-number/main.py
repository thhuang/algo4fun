class Solution:

    def missingNumber(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            while nums[i] != i and nums[i] < len(nums):
                j = nums[i]
                nums[i], nums[j] = nums[j], nums[i]
        for i in range(len(nums)):
            if i != nums[i]:
                return i
        return len(nums)
