class Solution:

    def minOperations(self, nums: List[int], k: int) -> int:
        for v in nums:
            k = k ^ v

        result = 0
        mask = 1
        while k != 0:
            if k & mask != 0:
                k = k ^ mask
                result += 1
            mask = mask << 1

        return result
