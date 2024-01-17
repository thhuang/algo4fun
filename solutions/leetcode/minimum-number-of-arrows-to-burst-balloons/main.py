class Solution:

    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda p: p[1])

        result = 0

        x = -inf
        for l, r in points:
            if l <= x:
                continue
            else:
                x = r
                result += 1

        return result
