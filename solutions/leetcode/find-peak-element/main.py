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
