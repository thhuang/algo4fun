class Solution:

    def minSteps(self, s: str, t: str) -> int:
        freq = defaultdict(int)
        for i in range(len(s)):
            freq[s[i]] += 1
            freq[t[i]] -= 1
        result = 0
        for _, v in freq.items():
            result += max(0, v)
        return result
