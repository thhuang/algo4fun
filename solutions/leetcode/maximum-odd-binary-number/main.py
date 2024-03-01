class Solution:

    def maximumOddBinaryNumber(self, s: str) -> str:
        n = len(s)

        ones = s.count("1")

        result = []
        for _ in range(ones - 1):
            result.append("1")
        for _ in range(n - ones):
            result.append("0")
        result.append("1")

        return "".join(result)
