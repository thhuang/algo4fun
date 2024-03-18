class Solution:

    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda p: p[1])

        result = 0
        x = -inf

        for l, r in points:
            if l <= x:
                continue

            result += 1
            x = r

        return result
