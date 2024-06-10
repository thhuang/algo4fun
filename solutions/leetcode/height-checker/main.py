class Solution:

    def heightChecker(self, heights: List[int]) -> int:
        result = 0
        for i, h in enumerate(sorted(heights)):
            if heights[i] != h:
                result += 1
        return result
