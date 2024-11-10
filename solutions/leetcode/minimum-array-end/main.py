class Solution:

    def minEnd(self, n: int, x: int) -> int:
        xbin = [x & (1 << i) != 0 for i in range(62)]

        p = 0
        for i in range(31):
            while xbin[p]:
                p += 1
            xbin[p] = (n - 1) & (1 << i) != 0
            p += 1

        result = 0
        for i, b in enumerate(xbin):
            if b:
                result += 1 << i

        return result
