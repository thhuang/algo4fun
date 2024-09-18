class Solution:

    def findBuildings(self, heights: List[int]) -> List[int]:
        result = []
        for i, h in enumerate(heights):
            while len(result) > 0 and heights[result[-1]] <= h:
                result.pop()
            result.append(i)
        return result


class Solution:

    def findBuildings(self, heights: List[int]) -> List[int]:
        rresult = []
        for i, h in reversed(list(enumerate(heights))):
            if len(rresult) == 0 or heights[rresult[-1]] < h:
                rresult.append(i)
        return reversed(rresult)
