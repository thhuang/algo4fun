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
            while l < r and nums[l] == nums[l - 1]:
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
            while p + 2 < len(nums) and nums[p] == nums[p - 1]:
                p = p + 1

        return result


class Solution:

    def twoSumSorted(self, nums: list[int], start: int,
                     target: int) -> list[list[int]]:
        l = start
        r = len(nums) - 1

        result = []

        while l < r:
            s = nums[l] + nums[r]
            if s < target:
                l += 1
            elif s > target:
                r -= 1
            else:
                result.append([l, r])
                l += 1
                r -= 1
                while l < r and nums[l] == nums[l - 1]:
                    l += 1
                while l < r and nums[r] == nums[r + 1]:
                    r -= 1

        return result

    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums = sorted(nums)

        result = []

        for i in range(0, len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            for j, k in self.twoSumSorted(nums, i + 1, -nums[i]):
                result.append([nums[i], nums[j], nums[k]])

        return result
