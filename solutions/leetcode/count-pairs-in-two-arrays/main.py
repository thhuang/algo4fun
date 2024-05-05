class Solution:

    def countPairs(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        diff = sorted([nums1[i] - nums2[i] for i in range(n)])

        result = 0

        r = n - 1
        for l in range(n):
            r = max(r, l)
            while l < r and diff[l] + diff[r] > 0:
                r -= 1
            result += n - 1 - r

        return result
