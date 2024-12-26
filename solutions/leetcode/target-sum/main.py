class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp = {}
        dp[0] = 1

        for num in nums:
            dp_new = {}
            for k, v in dp.items():
                dp_new[k - num] = dp_new.get(k - num, 0) + v
                dp_new[k + num] = dp_new.get(k + num, 0) + v
            dp = dp_new

        return dp.get(target, 0)
