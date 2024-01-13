class Solution:

    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda interval: (interval[1], interval[0]))

        result = 0

        p = -inf
        for l, r in intervals:
            if l < p:
                result += 1
            else:
                p = r

        return result
