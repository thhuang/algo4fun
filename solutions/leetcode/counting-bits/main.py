class Solution:

    def countBits(self, n: int) -> List[int]:
        result = [0]

        b = 1
        while True:
            for i in range(b):
                if len(result) > n:
                    return result
                result.append(result[i] + 1)

            b = b << 1

        return []


class Solution:

    def countBits(self, n: int) -> List[int]:
        result = [0] * (n + 1)

        b = 1
        for r in range(1, n + 1):
            if r >= b * 2:
                b *= 2
            l = r - b
            result[r] = result[l] + 1

        return result


class Solution:

    def countBits(self, n: int) -> List[int]:
        result = [0] * (n + 1)

        for i in range(1, n + 1):
            result[i] = result[i & (i - 1)] + 1

        return result
