class Solution:

    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        result = 0

        window = 1
        l = 0
        for r in range(len(nums)):
            window *= nums[r]
            while l <= r and window >= k:
                window //= nums[l]
                l += 1
            result += r - l + 1

        return result
