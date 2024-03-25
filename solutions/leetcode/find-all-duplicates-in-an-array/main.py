class Solution:

    def findDuplicates(self, nums: List[int]) -> List[int]:
        result = []
        for i in range(len(nums)):
            j = abs(nums[i]) - 1
            if nums[j] < 0:
                result.append(j + 1)
            else:
                nums[j] = -nums[j]
        for i in range(len(nums)):
            nums[i] = abs(nums[i])
        return result
