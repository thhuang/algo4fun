class Solution:

    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        set1, set2 = set(nums1), set(nums2)
        common = [v for v in set1 if v in set2]
        return min(common) if len(common) > 0 else -1
