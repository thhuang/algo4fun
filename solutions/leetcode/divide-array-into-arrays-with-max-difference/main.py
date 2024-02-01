class Solution:

    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()

        result = []

        l = 0
        while l < len(nums):
            r = l + 3
            if nums[l] + k < nums[r - 1]:
                return []
            result.append(nums[l:r])
            l = r

        return result
