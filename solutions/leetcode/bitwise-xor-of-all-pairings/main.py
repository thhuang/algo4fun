class Solution:

    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        result = 0
        if len(nums2) % 2 == 1:
            result ^= reduce(lambda acc, x: acc ^ x, nums1, 0)
        if len(nums1) % 2 == 1:
            result ^= reduce(lambda acc, x: acc ^ x, nums2, 0)
        return result
