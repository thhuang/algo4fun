class Solution:

    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        charIndex = dict()

        result = -1
        for i in range(len(s)):
            if s[i] not in charIndex:
                charIndex[s[i]] = i
            else:
                result = max(result, i - charIndex[s[i]] - 1)

        return result
