class Solution:

    def singleNonDuplicate(self, nums: List[int]) -> int:
        l, r = -1, len(nums) - 1  # (l, r]
        while r - l > 1:
            m = l + (r - l) // 2
            if m % 2 == 1:
                if nums[m - 1] == nums[m]:
                    l = m
                else:
                    r = m
            else:
                if nums[m] == nums[m + 1]:
                    l = m
                else:
                    r = m

        return nums[r]
