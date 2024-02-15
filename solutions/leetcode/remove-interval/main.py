class Solution:

    def removeInterval(self, intervals: List[List[int]],
                       toBeRemoved: List[int]) -> List[List[int]]:
        intervals.sort()

        result = []

        def append(new_interval):
            nonlocal result
            if new_interval[0] < new_interval[1]:
                result.append(new_interval)

        for interval in intervals:
            if interval[1] <= toBeRemoved[0] or toBeRemoved[1] <= interval[0]:
                append(interval)
            else:
                append([interval[0], toBeRemoved[0]])
                append([toBeRemoved[1], interval[1]])

        return result
