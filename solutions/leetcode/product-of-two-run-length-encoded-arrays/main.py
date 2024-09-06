class Solution:

    def findRLEArray(self, encoded1: List[List[int]], encoded2: List[List[int]]) -> List[List[int]]:
        result = []
        i, j = 0, 0

        while i < len(encoded1) and j < len(encoded2):
            l = min(encoded1[i][1], encoded2[j][1])
            v = encoded1[i][0] * encoded2[j][0]
            if len(result) == 0 or result[-1][0] != v:
                result.append([v, l])
            else:
                result[-1][1] += l

            encoded1[i][1] -= l
            if encoded1[i][1] == 0:
                i += 1

            encoded2[j][1] -= l
            if encoded2[j][1] == 0:
                j += 1

        return result
