class Solution:

    def largestRectangleArea(self, heights: List[int]) -> int:
        heights.append(0)

        result = 0
        incr = [(0, -1)]
        for i, h in enumerate(heights):
            l = i
            while len(incr) > 0 and incr[-1][0] > h:
                l = incr[-1][1]
                w = i - l
                result = max(result, w * incr[-1][0])
                incr.pop()
            incr.append((h, l))

        return result


class Solution:

    def largestRectangleArea(self, heights: List[int]) -> int:
        Rect = namedtuple("Rect", ["h", "i"])

        heights.append(0)
        incr = [Rect(0, -1)]
        result = 0

        for i, h in enumerate(heights):
            l = i
            while len(incr) > 0 and incr[-1].h > h:
                bar = incr.pop()
                l = bar.i
                w = i - bar.i
                result = max(result, bar.h * w)
            incr.append(Rect(h, l))

        return result
