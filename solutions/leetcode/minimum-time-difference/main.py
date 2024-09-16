class Solution:

    def findMinDifference(self, time_points: List[str]) -> int:

        def timeToSec(t: str) -> int:
            return 60 * int(t[:2]) + int(t[3:])

        secs = sorted([60 * int(t[:2]) + int(t[3:]) for t in time_points])

        result = 24 * 60 + secs[0] - secs[-1]
        for i in range(1, len(secs)):
            result = min(result, secs[i] - secs[i - 1])

        return result
