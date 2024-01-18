class Solution:

    def maxOperations(self, nums: List[int], k: int) -> int:
        result = 0

        num_freq = defaultdict(int)
        for v in nums:
            w = k - v
            if num_freq[w] > 0:
                result += 1
                num_freq[w] -= 1
            else:
                num_freq[v] += 1

        return result
