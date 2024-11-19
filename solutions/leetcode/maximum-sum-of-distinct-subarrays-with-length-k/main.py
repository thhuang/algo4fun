class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        frequency = defaultdict(int)
        distinct_count = 0
        window = 0
        result = 0

        for r in range(len(nums)):
            frequency[nums[r]] += 1
            window += nums[r]
            if frequency[nums[r]] == 1:
                distinct_count += 1

            if distinct_count == k:
                result = max(result, window)

            if r < k - 1:
                continue

            l = r - k + 1
            frequency[nums[l]] -= 1
            window -= nums[l]
            if frequency[nums[l]] == 0:
                distinct_count -= 1

        return result
