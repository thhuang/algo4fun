class Solution:

    def findPeakElement(self, nums: List[int]) -> int:
        l, r = 0, len(nums)
        while r - l > 1:
            m = (l + r) // 2
            if nums[m - 1] < nums[m]:
                l = m
            else:
                r = m
        return l


class Solution:

    def findPeakElement(self, nums: List[int]) -> int:
        inf = float('inf')
        n = len(nums)

        l, r = -1, n  # [l, r)
        while r - l > 1:
            m = (l + r) // 2
            a = nums[m - 1] if m - 1 >= 0 else -inf
            b = nums[m] if m < n else -inf
            if a < b:
                l = m
            else:  # a > b
                r = m

        return l
