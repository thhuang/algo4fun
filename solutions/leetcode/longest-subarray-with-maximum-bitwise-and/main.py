class Solution:

    def longestSubarray(self, nums: List[int]) -> int:
        mx = 0
        result = 1

        nums.append(0)

        l = 0
        for r in range(len(nums)):
            if nums[r] != nums[l]:
                if nums[l] == mx:
                    result = max(result, r - l)
                elif nums[l] > mx:
                    result = r - l
                    mx = nums[l]
                l = r

        return result
