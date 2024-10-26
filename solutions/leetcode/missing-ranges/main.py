class Solution:

    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[List[int]]:
        nums.append(upper + 1)

        result = []

        l = lower
        for r in nums:
            if l < r:
                result.append([l, r - 1])
            l = r + 1

        return result
