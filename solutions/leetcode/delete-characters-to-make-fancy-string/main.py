class Solution:

    def makeFancyString(self, s: str) -> str:
        result = []
        for c in s:
            result.append(c)
            if len(result) >= 3 and result[-1] == result[-2] == result[-3]:
                result.pop()
        return "".join(result)
