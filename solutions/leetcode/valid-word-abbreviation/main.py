class Solution:

    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        m, n = len(word), len(abbr)
        i, j = 0, 0

        def getNumber() -> int:
            nonlocal j
            v = 0
            while j < n and abbr[j].isdigit():
                v = v * 10 + int(abbr[j])
                j += 1
            return v

        while i < m and j < n:
            if abbr[j].isdigit():
                if abbr[j] == "0":
                    return False
                v = getNumber()
                i += v
            elif word[i] != abbr[j]:
                return False
            else:
                i += 1
                j += 1

        return i == m and j == n


class Solution:

    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        m = len(word)
        n = len(abbr)

        i = 0
        j = 0

        while i < m and j < n:
            if abbr[j].isalpha():
                if word[i] != abbr[j]:
                    return False
                i += 1
                j += 1
            elif abbr[j] == "0":
                return False
            else:
                v = 0
                while j < n and abbr[j].isdigit():
                    v = v * 10 + int(abbr[j])
                    j += 1
                if m - i < v:
                    return False
                i += v

        return i == m and j == n
