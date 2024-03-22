class Solution:
    vowels = {'a', 'e', 'i', 'o', 'u'}

    def removeVowels(self, s: str) -> str:
        return "".join(filter(lambda c: c not in self.vowels, s))
