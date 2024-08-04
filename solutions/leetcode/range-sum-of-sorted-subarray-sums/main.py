class Solution:

    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        n = len(nums)
        sums = []
        for l in range(n):
            v = 0
            for r in range(l, n):
                v += nums[r]
                sums.append(v)
        sums.sort()
        return sum(sums[left - 1:right]) % (10**9 + 7)
