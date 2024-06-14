class Solution:

    def minIncrementForUnique(self, nums: List[int]) -> int:
        nums.sort()

        result = 0

        for i in range(1, len(nums)):
            if nums[i - 1] < nums[i]:
                continue
            diff = nums[i - 1] + 1 - nums[i]
            nums[i] += diff
            result += diff

        return result


class Solution:

    def minIncrementForUnique(self, nums: List[int]) -> int:
        freq = dict()
        for v in nums:
            freq[v] = freq.get(v, 0) + 1

        result = 0

        for v in range(min(nums), max(nums) + len(nums)):
            if freq.get(v, 0) > 1:
                freq[v + 1] = freq.get(v + 1, 0) + freq[v] - 1
                result += freq[v] - 1

        return result
