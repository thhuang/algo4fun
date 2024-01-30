class Solution:

    def minFlips(self, a: int, b: int, c: int) -> int:
        n = 32
        result = 0
        for i in range(n):
            mask = 1 << i
            if c & mask:
                if (a | b) & mask:
                    continue
                result += 1
            else:
                if a & mask:
                    result += 1
                if b & mask:
                    result += 1
        return result
