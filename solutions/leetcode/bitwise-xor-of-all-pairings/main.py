class Solution:

    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        xors = lambda nums: reduce(lambda acc, x: acc ^ x, nums, 0)

        result = 0

        if len(nums2) % 2 == 1:
            result ^= xors(nums1)
        if len(nums1) % 2 == 1:
            result ^= xors(nums2)

        return result
