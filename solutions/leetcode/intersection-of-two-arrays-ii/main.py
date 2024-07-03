class Solution:

    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        freq = Counter(nums1)
        result = []
        for v in nums2:
            if v not in freq:
                continue
            if freq[v] == 0:
                continue
            freq[v] -= 1
            result.append(v)
        return result
