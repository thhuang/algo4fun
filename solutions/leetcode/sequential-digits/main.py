class Solution:

    def sequentialDigits(self, low: int, high: int) -> List[int]:
        seq = "123456789"

        result = []

        for d in range(len(str(low)), len(str(high)) + 1):
            l = 0
            r = l + d
            while r <= len(seq):
                v = int(seq[l:r])
                if low <= v <= high:
                    result.append(v)
                l += 1
                r += 1

        return result


class Solution:

    def sequentialDigits(self, low: int, high: int) -> List[int]:
        seq = "123456789"

        result = []

        for d in range(len(str(low)), len(str(high)) + 1):
            for l in range(len(seq) - d + 1):
                v = int(seq[l:l + d])
                if low <= v <= high:
                    result.append(v)

        return result
