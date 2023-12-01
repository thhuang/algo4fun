class Solution:

    def twoSumLessThanK(self, nums: List[int], k: int) -> int:
        nums.sort()
        result = -1
        l, r = 0, len(nums) - 1
        while l < r:
            v = nums[l] + nums[r]
            if v >= k:
                r -= 1
            else:
                result = max(result, v)
                l += 1
        return result
