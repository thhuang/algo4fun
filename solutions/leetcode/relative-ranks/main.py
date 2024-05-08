class Solution:

    def findRelativeRanks(self, score: List[int]) -> List[str]:
        n = len(score)
        indices = [i for i in range(n)]
        result = [None] * n

        for r, i in enumerate(sorted(indices, key=lambda i: -score[i])):
            if r == 0:
                result[i] = "Gold Medal"
            elif r == 1:
                result[i] = "Silver Medal"
            elif r == 2:
                result[i] = "Bronze Medal"
            else:
                result[i] = str(r + 1)

        return result
