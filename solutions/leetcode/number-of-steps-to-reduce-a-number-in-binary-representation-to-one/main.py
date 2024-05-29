class Solution:

    def numSteps(self, s: str) -> int:
        result = 0

        v = int(s, 2)
        while v > 1:
            result += 1
            if v % 2 == 1:
                v += 1
            else:
                v //= 2

        return result
