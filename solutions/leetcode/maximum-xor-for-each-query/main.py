class Solution:

    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        cur = 0
        for v in nums:
            cur ^= v

        result = []
        for v in reversed(nums):
            b = (1 << maximumBit) - 1
            result.append((cur & b) ^ b)
            cur ^= v

        return result


class Solution:

    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        cur = reduce(lambda a, b: a ^ b, nums)

        result = []
        for v in reversed(nums):
            b = (1 << maximumBit) - 1
            result.append((cur & b) ^ b)
            cur ^= v

        return result
