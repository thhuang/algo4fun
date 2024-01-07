class Solution:

    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        result = 0
        dp = [defaultdict(int) for _ in range(len(nums))]
        for r in range(1, len(nums)):
            for l in range(0, r):
                d = nums[r] - nums[l]
                p = dp[l][d]
                result += p
                dp[r][d] += p + 1
        return result
