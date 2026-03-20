class Solution:

    def robLinear(self, nums: List[int]) -> int:
        dp = (0, 0)
        for v in nums:
            dp = (dp[1], max(dp[1], dp[0] + v))
        return dp[1]

    def rob(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return nums[0]
        return max(self.robLinear(nums[:-1]), self.robLinear(nums[1:]))
