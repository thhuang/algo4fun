class Solution:

    def getSpecialIntervals(self, nums: List[int]) -> List[Tuple[int, int]]:
        result = []

        l = 0
        while l < len(nums):
            r = l + 1
            while r < len(nums) and (nums[r - 1] + nums[r]) % 2 == 1:
                r += 1
            result.append((l, r - 1))
            l = r

        return result

    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        special_intervals = self.getSpecialIntervals(nums)

        result = []

        for l, r in queries:
            i = bisect_right(special_intervals, l, key=lambda interval: interval[0]) - 1
            result.append(r <= special_intervals[i][1])

        return result


class Solution:

    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        special_range = []

        l = 0
        while l < len(nums):
            r = l + 1
            while r < len(nums) and (nums[r - 1] + nums[r]) % 2 == 1:
                r += 1
            while l < r:
                special_range.append(r - 1)
                l += 1

        result = []
        for l, r in queries:
            result.append(r <= special_range[l])

        return result
