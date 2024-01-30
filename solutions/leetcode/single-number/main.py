class Solution:

    def singleNumber(self, nums: List[int]) -> int:
        result = 0
        for v in nums:
            result ^= v
        return result
