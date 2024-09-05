class Solution:

    def longestConsecutive(self, nums: List[int]) -> int:
        vis = set(nums)
        result = 0
        for l in nums:
            if l - 1 not in vis:
                r = l
                while r in vis:
                    r += 1
                result = max(result, r - l)
        return result
