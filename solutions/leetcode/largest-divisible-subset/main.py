class Solution:

    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()

        n = len(nums)

        dp, prev = [1] * n, [-1] * n
        for r in range(n):
            for l in range(r):
                if nums[r] % nums[l] != 0:
                    continue
                if dp[r] >= dp[l] + 1:
                    continue
                dp[r], prev[r] = dp[l] + 1, l

        result = []
        i = dp.index(max(dp))
        while i >= 0:
            result.append(nums[i])
            i = prev[i]

        return result
