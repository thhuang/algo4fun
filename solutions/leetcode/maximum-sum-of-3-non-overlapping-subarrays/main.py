class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        suffix_sum = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            suffix_sum[i] = suffix_sum[i + 1] + nums[i]

        left_max = [None] * n
        mx = -1
        for r in range(k - 1, n):
            l = r - k + 1
            v = suffix_sum[l] - suffix_sum[r + 1]
            if v > mx:
                left_max[r] = (v, l)
                mx = v
            else:
                left_max[r] = left_max[r - 1]

        right_max = [None] * n
        mx = -1
        for l in range(n - k, -1, -1):
            r = l + k - 1
            v = suffix_sum[l] - suffix_sum[r + 1]
            if v >= mx:
                right_max[l] = (v, l)
                mx = v
            else:
                right_max[l] = right_max[l + 1]

        result = None
        mx = -1
        for i in range(k, n - k * 2 + 1):
            mid = suffix_sum[i] - suffix_sum[i + k]
            s = left_max[i - 1][0] + mid + right_max[i + k][0]
            if s > mx:
                result = [left_max[i - 1][1], i, right_max[i + k][1]]
                mx = s

        return result
