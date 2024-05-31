class Solution:

    def singleNumber(self, nums: List[int]) -> List[int]:
        axorb = 0
        for v in nums:
            axorb ^= v

        mask = axorb & -axorb

        a = 0
        for v in nums:
            if v & mask != 0:
                a ^= v

        return [a, axorb ^ a]
