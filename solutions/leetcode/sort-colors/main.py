class Solution:

    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        p, l, r = 0, 0, len(nums) - 1
        while p <= r:
            if nums[p] == 0:
                nums[p], nums[l] = nums[l], nums[p]
                l += 1
                p += 1
            elif nums[p] == 2:
                nums[p], nums[r] = nums[r], nums[p]
                r -= 1
            else:
                p += 1
