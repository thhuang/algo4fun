class Solution:

    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        return "".join(word1) == "".join(word2)


class Solution:

    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        i1, i2 = 0, 0
        j1, j2 = 0, 0
        while True:
            print(i1, j1, i2, j2)
            if i1 == len(word1) and i2 == len(word2):
                return True
            if i1 == len(word1) or i2 == len(word2):
                return False
            if j1 < len(word1[i1]) and j2 < len(word2[i2]):
                if word1[i1][j1] != word2[i2][j2]:
                    return False
                else:
                    j1 += 1
                    j2 += 1
            else:
                if j1 == len(word1[i1]):
                    j1 = 0
                    i1 += 1
                if j2 == len(word2[i2]):
                    j2 = 0
                    i2 += 1


class Solution:

    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        i1, i2, j1, j2 = 0, 0, 0, 0
        while i1 < len(word1) and i2 < len(word2):
            if j1 < len(word1[i1]) and j2 < len(word2[i2]):
                if word1[i1][j1] != word2[i2][j2]:
                    return False
                j1 += 1
                j2 += 1
            else:
                if j1 == len(word1[i1]):
                    j1 = 0
                    i1 += 1
                if j2 == len(word2[i2]):
                    j2 = 0
                    i2 += 1
        return i1 == len(word1) and i2 == len(word2)
