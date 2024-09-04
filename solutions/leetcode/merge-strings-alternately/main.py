class Solution:

    def mergeAlternately(self, word1: str, word2: str) -> str:
        n1, n2 = len(word1), len(word2)
        mn = min(n1, n2)

        result = []
        for i in range(mn):
            result.append(word1[i])
            result.append(word2[i])

        for i in range(mn, n1):
            result.append(word1[i])
        for i in range(mn, n2):
            result.append(word2[i])

        return ''.join(result)


class Solution:

    def mergeAlternately(self, word1: str, word2: str) -> str:
        m, n = len(word1), len(word2)
        i, j = 0, 0
        result = []
        while i < m or j < n:
            if i < m:
                result.append(word1[i])
                i += 1
            if j < n:
                result.append(word2[j])
                j += 1
        return "".join(result)
