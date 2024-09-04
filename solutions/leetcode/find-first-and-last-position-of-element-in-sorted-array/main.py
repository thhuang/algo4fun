class Solution:

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l = bisect.bisect_left(nums, target)
        r = bisect.bisect_right(nums, target)
        if l == r:
            return [-1, -1]
        return [l, r - 1]


class Solution:

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)

        def upper_bound():
            l, r = -1, n  # [l, r)
            while r - l > 1:
                m = (l + r) // 2
                if nums[m] <= target:
                    l = m
                else:
                    r = m
            return l

        def lower_bound():
            l, r = -1, n  # (l, r]
            while r - l > 1:
                m = (l + r) // 2
                if nums[m] < target:
                    l = m
                else:
                    r = m
            return r

        l, r = lower_bound(), upper_bound()
        if l > r:
            return [-1, -1]
        return [l, r]
