class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        result = -float("inf")
        mx = values[0]
        for i in range(1, len(values)):
            result = max(result, mx + values[i] - i)
            mx = max(mx, values[i] + i)
        return result
