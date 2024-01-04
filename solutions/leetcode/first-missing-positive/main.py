class Solution:

    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.append(0)
        for i in range(len(nums)):
            while i != nums[i] and 0 <= nums[i] < len(nums) and nums[i] != nums[nums[i]]:
                j = nums[i]
                nums[i], nums[j] = nums[j], nums[i]
        for i in range(len(nums)):
            if i != nums[i]:
                return i
        return len(nums)
