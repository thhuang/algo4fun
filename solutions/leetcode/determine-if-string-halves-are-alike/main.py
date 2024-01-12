class Solution:

    def halvesAreAlike(self, s: str) -> bool:
        vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        vowel_count = 0
        for i in range(len(s)):
            if s[i] not in vowels:
                continue
            if i < len(s) // 2:
                vowel_count += 1
            else:
                vowel_count -= 1
        return vowel_count == 0
