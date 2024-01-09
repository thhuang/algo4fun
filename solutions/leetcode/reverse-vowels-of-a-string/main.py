class Solution:

    def reverseVowels(self, s: str) -> str:
        isVowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        vowels = []
        for c in s:
            if c in isVowels:
                vowels.append(c)
        result = []
        for c in s:
            if c in isVowels:
                result.append(vowels.pop())
            else:
                result.append(c)
        return "".join(result)
