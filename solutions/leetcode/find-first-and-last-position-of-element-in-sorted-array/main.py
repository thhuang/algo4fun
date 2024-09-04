class Solution:

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l = bisect.bisect_left(nums, target)
        r = bisect.bisect_right(nums, target)
        if l == r:
            return [-1, -1]
        return [l, r - 1]
