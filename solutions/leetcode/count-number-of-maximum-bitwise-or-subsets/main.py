class Solution:

    def countMaxOrSubsets(self, nums: List[int]) -> int:
        dp = {0: 1}
        mx = 0
        for num in nums:
            for v, cnt in list(dp.items()):
                dp[v | num] = dp.get(v | num, 0) + cnt
            mx |= num
        return dp[mx]
