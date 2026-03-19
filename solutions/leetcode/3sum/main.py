class Solution:

    def twoSumSorted(self, nums: list[int], start: int,
                     target: int) -> list[list[int]]:
        l = start
        r = len(nums) - 1

        result = []

        while l < r:
            if nums[l] + nums[r] > target:
                r = r - 1
                continue

            if nums[l] + nums[r] == target:
                result.append([nums[l], nums[r]])

            l = l + 1
            while nums[l] == nums[l - 1] and l < r:
                l = l + 1

        return result

    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums = sorted(nums)

        result = []

        p = 0
        while p + 2 < len(nums):
            candidates = self.twoSumSorted(nums, p + 1, -nums[p])
            for l, r in candidates:
                result.append([nums[p], l, r])

            p = p + 1
            while nums[p] == nums[p - 1] and p + 2 < len(nums):
                p = p + 1

        return result
