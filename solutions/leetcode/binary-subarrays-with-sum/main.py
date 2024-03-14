class Solution:

    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        prefix_sum_freq = defaultdict(int)
        prefix_sum_freq[0] = 1

        result = 0
        prefix_sum = 0
        for v in nums:
            prefix_sum += v
            result += prefix_sum_freq[prefix_sum - goal]
            prefix_sum_freq[prefix_sum] += 1

        return result
