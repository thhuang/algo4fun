class Solution:

    def pivotIndex(self, nums: List[int]) -> int:
        left = 0
        right = sum(nums)

        for i in range(len(nums)):
            right -= nums[i]

            if left == right:
                return i

            left += nums[i]

        return -1
