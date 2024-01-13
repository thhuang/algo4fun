class Solution:

    def minSteps(self, s: str, t: str) -> int:
        freq = defaultdict(int)
        for c in s:
            freq[c] += 1
        for c in t:
            freq[c] -= 1
        result = 0
        for _, v in freq.items():
            if v > 0:
                result += v
        return result
