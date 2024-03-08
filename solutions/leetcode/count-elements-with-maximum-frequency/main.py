class Solution:

    def maxFrequencyElements(self, nums: List[int]) -> int:
        freq = Counter(nums)
        max_freq = max(freq.values())
        return list(freq.values()).count(max_freq) * max_freq
