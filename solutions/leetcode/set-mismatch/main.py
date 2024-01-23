class Solution:

    def findErrorNums(self, nums: List[int]) -> List[int]:
        nums.append(0)
        for i in range(len(nums)):
            while nums[i] != i and nums[i] != nums[nums[i]]:
                j = nums[i]
                nums[i], nums[j] = nums[j], nums[i]
        for i, v in enumerate(nums):
            if i != v:
                return [v, i]
        return None
