class Solution:

    def lengthOfLIS(self, nums: List[int]) -> int:
        seq = []
        for v in nums:
            i = bisect.bisect_left(seq, v)
            if i == len(seq):
                seq.append(v)
            else:
                seq[i] = v
        return len(seq)


class Solution:

    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n

        for r in range(1, n):
            for l in range(0, r):
                if nums[l] < nums[r]:
                    dp[r] = max(dp[r], dp[l] + 1)

        return max(dp)
