class Solution:

    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        events = []
        for start, end in intervals:
            events.append((start, 1))
            events.append((end, -1))

        events.sort()

        result = 0
        curr = 0
        for _, diff in events:
            curr += diff
            result = max(result, curr)

        return result
