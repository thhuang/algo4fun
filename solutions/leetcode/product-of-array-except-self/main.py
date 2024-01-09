class Solution:

    def productExceptSelf(self, nums: List[int]) -> List[int]:
        result = [1]
        for v in nums:
            result.append(result[-1] * v)
        result.pop()

        v = nums[-1]
        for i in range(1, len(nums)):
            result[-1 - i] *= v
            v *= nums[-1 - i]

        return result
