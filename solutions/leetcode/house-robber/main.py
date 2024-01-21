class Solution:

    def rob(self, nums: List[int]) -> int:
        dp = (0, nums[0])
        for i in range(1, len(nums)):
            dp = (dp[1], max(dp[1], dp[0] + nums[i]))
        return dp[1]
