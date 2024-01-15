class Solution:

    def longestSubarray(self, nums: List[int]) -> int:
        result = 0
        deleted = 0
        l = 0
        for r in range(len(nums)):
            if nums[r] == 0:
                deleted += 1
            while deleted > 1:
                if nums[l] == 0:
                    deleted -= 1
                l += 1
            result = max(result, r - l)
        return result
