class Solution:

    def minSubarray(self, nums: List[int], p: int) -> int:
        k = sum(nums) % p
        if k == 0:
            return 0

        result = len(nums)

        prefix = {0: -1}
        r = 0
        for i, v in enumerate(nums):
            r = (r + v) % p
            t = (r - k + p) % p
            if t in prefix:
                result = min(result, i - prefix[t])
            prefix[r] = i

        if result == len(nums):
            return -1
        return result
