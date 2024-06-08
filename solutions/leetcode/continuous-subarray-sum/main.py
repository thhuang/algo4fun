class Solution:

    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        prefix = {0}
        s = 0
        for i in range(1, len(nums)):
            s = (s + nums[i - 1]) % k
            if (s + nums[i]) % k in prefix:
                return True
            prefix.add(s)
        return False
