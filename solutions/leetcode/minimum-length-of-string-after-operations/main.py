class Solution:

    def minimumLength(self, s: str) -> int:
        result = 0
        for v in Counter(s).values():
            if v < 3:
                result += v
            elif v % 2 == 0:
                result += 2
            else:
                result += 1
        return result
