class Solution:

    def maxVowels(self, s: str, k: int) -> int:
        vowels = {'a', 'e', 'i', 'o', 'u'}

        result = 0
        curr = 0

        for r in range(len(s)):
            l = r - k + 1

            if s[r] in vowels:
                curr += 1

            result = max(result, curr)

            if l >= 0 and s[l] in vowels:
                curr -= 1

        return result
