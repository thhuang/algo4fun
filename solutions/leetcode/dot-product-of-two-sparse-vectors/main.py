class SparseVector:

    def __init__(self, nums: List[int]):
        self.data = dict()
        for i, v in enumerate(nums):
            if v != 0:
                self.data[i] = v

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: 'SparseVector') -> int:
        a = self.data
        b = vec.data
        result = 0
        if len(a) > len(b):
            a, b = b, a
        for i, v in a.items():
            result += v * b.get(i, 0)
        return result


# Your SparseVector object will be instantiated and called as such:
# v1 = SparseVector(nums1)
# v2 = SparseVector(nums2)
# ans = v1.dotProduct(v2)
