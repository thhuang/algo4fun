class Solution:

    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        result = 0

        freq = defaultdict(int)
        l = 0

        for r in range(len(nums)):
            c = nums[r]
            freq[c] += 1
            while freq[c] > k:
                freq[nums[l]] -= 1
                l += 1
            result = max(result, r - l + 1)

        return result
