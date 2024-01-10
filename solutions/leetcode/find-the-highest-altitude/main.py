class Solution:

    def largestAltitude(self, gain: List[int]) -> int:
        result = 0
        h = 0
        for v in gain:
            h += v
            result = max(result, h)
        return result
