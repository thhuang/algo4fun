class Solution:

    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
        n = len(nums)
        m = len(multipliers)

        dp = [0] * (m + 1)
        for i in reversed(range(m)):
            dp_new = [0] * (m + 1)
            for j in range(i + 1):
                length = n - i
                l = j
                r = l + length - 1
                k = multipliers[i]
                dp_new[j] = max(
                    k * nums[l] + dp[j + 1],
                    k * nums[r] + dp[j],
                )
            dp = dp_new

        return dp[0]
