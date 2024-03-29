class Solution:

    def countSubarrays(self, nums: List[int], k: int) -> int:
        mx = max(nums)

        result = 0

        window = 0
        l = 0

        for r in range(len(nums)):
            if nums[r] == mx:
                window += 1
            while window >= k:
                if nums[l] == mx:
                    window -= 1
                l += 1
            result += l

        return result
