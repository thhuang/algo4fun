class Solution:

    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        result = 0
        l = 0
        for r in range(len(s)):
            maxCost -= abs(ord(s[r]) - ord(t[r]))
            while l <= r and maxCost < 0:
                maxCost += abs(ord(s[l]) - ord(t[l]))
                l += 1
            result = max(result, r - l + 1)
        return result
