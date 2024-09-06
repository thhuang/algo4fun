class Solution:

    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            m = (l + r) // 2
            if nums[m] <= nums[r] and (target < nums[m] or nums[r] < target):
                r = m - 1
            elif nums[m] > nums[r] and nums[r] < target < nums[m]:
                r = m - 1
            else:
                l = m + 1
        return r if nums[r] == target else -1
