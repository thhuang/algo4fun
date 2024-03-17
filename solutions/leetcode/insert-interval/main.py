class Solution:

    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:

        result = []
        n = len(intervals)
        i = 0

        while i < n and intervals[i][1] < newInterval[0]:
            result.append(intervals[i])
            i += 1

        result.append(newInterval)

        while i < n and intervals[i][0] <= result[-1][1]:
            result[-1][0] = min(result[-1][0], intervals[i][0])
            result[-1][1] = max(result[-1][1], intervals[i][1])
            i += 1

        while i < n:
            result.append(intervals[i])
            i += 1

        return result
