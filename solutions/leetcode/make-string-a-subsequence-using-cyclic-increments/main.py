class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        def incr(c: str) -> str:
            return chr(ord("a") + (ord(c) - ord("a") + 1) % 26)

        i = 0
        j = 0
        while i < len(str1) and j < len(str2):
            if str1[i] == str2[j] or incr(str1[i]) == str2[j]:
                i += 1
                j += 1
            else:
                i += 1

        return j == len(str2)
