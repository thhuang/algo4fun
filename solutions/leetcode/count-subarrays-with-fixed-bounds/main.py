class Solution:

    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        result = 0

        mn, mx, l = -1, -1, -1

        for r in range(len(nums)):
            v = nums[r]

            if v < minK or maxK < v:
                l = r
                continue

            if v == minK:
                mn = r
            if v == maxK:
                mx = r

            result += max(0, min(mn, mx) - l)

        return result
