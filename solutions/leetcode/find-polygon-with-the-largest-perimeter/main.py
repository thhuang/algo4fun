class Solution:

    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()

        result = -1
        p = nums[0] + nums[1]
        for v in nums[2:]:
            if p > v:
                result = p + v
            p += v

        return result
