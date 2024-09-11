class Solution:

    def minBitFlips(self, start: int, goal: int) -> int:
        result = 0
        v = start ^ goal
        while v > 0:
            if v & 1 != 0:
                result += 1
            v >>= 1
        return result
