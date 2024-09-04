class Solution:

    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        s = nums[0] % k
        prefix_sum = {0}
        for i in range(1, len(nums)):
            r = (s + nums[i]) % k
            if r in prefix_sum:
                return True
            prefix_sum.add(s)
            s = r
        return False


class Solution:

    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        s = 0
        prefix = {0}
        for i in range(1, len(nums)):
            s = (s + nums[i - 1]) % k
            if (s + nums[i]) % k in prefix:
                return True
            prefix.add(s)
        return False
