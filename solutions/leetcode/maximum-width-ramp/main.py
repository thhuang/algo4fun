class Solution:

    def maxWidthRamp(self, nums: List[int]) -> int:
        decr = []
        for i in range(len(nums)):
            if len(decr) == 0 or nums[decr[-1]] > nums[i]:
                decr.append(i)

        result = 0

        for i in reversed(range(len(nums))):
            while len(decr) > 0 and nums[decr[-1]] <= nums[i]:
                result = max(result, i - decr[-1])
                decr.pop()

        return result
