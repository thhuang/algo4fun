class Solution:

    def findMin(self, nums: List[int]) -> int:
        result = inf

        l, r = 0, len(nums) - 1

        while l <= r:
            m = l + (r - l) // 2
            result = min(result, nums[m])
            if nums[m] < nums[r]:
                r = m - 1
            else:
                l = m + 1

        return result
