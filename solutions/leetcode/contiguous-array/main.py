class Solution:

    def findMaxLength(self, nums: List[int]) -> int:
        result = 0
        score_index = {0: -1}

        score = 0
        for i, v in enumerate(nums):
            score += v * 2 - 1
            if score in score_index:
                result = max(result, i - score_index[score])
            else:
                score_index[score] = i

        return result
