class Solution:

    def minPatches(self, nums: List[int], n: int) -> int:
        result = 0
        r = 1
        i = 0
        while r <= n:
            if i < len(nums) and nums[i] <= r:
                r += nums[i]
                i += 1
            else:
                r += r
                result += 1
        return result
