class Solution:

    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        n = len(nums)

        result = 0

        l, r = 0, 0
        flipped = 0
        while r < n:
            if nums[r] == 0:
                flipped += 1
            while flipped > 1:
                if nums[l] == 0:
                    flipped -= 1
                l += 1
            result = max(result, r - l + 1)
            r += 1

        return result
