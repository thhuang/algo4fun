class Solution:

    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)
        ones = nums.count(1)

        window = 0
        for i in range(ones):
            if nums[i] == 0:
                window += 1

        result = len(nums)
        for l in range(n):
            result = min(result, window)
            if nums[l] == 0:
                window -= 1
            r = (l + ones) % n
            if nums[r] == 0:
                window += 1

        return result
