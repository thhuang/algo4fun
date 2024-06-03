class Solution:

    def appendCharacters(self, s: str, t: str) -> int:
        i = 0

        for c in s:
            if c != t[i]:
                continue

            i += 1
            if i == len(t):
                return 0

        return len(t) - i
