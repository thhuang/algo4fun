class Solution:

    def longestSquareStreak(self, nums: List[int]) -> int:
        num_set = set(nums)
        result = 0
        for v in nums:
            streak = 1
            v *= v
            while v in num_set:
                streak += 1
                v *= v
            result = max(result, streak)
        return result if result > 1 else -1
