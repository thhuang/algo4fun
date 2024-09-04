class Solution:

    def subarraySum(self, nums: List[int], k: int) -> int:
        result = 0

        prefix_sum = defaultdict(int)
        prefix_sum[0] = 1

        s = 0
        for v in nums:
            s += v
            result += prefix_sum[s - k]
            prefix_sum[s] += 1

        return result
