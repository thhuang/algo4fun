class Solution:

    def maxWidthRamp(self, nums: List[int]) -> int:
        incr = []
        for i in range(len(nums)):
            if len(incr) == 0 or nums[incr[-1]] > nums[i]:
                incr.append(i)

        result = 0

        for i in reversed(range(len(nums))):
            while len(incr) > 0 and nums[incr[-1]] <= nums[i]:
                result = max(result, i - incr[-1])
                incr.pop()

        return result
