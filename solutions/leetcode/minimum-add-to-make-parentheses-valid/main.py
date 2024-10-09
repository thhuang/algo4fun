class Solution:

    def minAddToMakeValid(self, s: str) -> int:
        open = 0
        for c in s:
            if c == "(":
                open += 1
            else:
                open = max(0, open - 1)

        close = 0
        for c in s[::-1]:
            if c == ")":
                close += 1
            else:
                close = max(0, close - 1)

        return open + close


class Solution:

    def minAddToMakeValid(self, s: str) -> int:
        result = 0

        opens = 0
        for c in s:
            if c == "(":
                opens += 1
            elif opens == 0:
                result += 1
            else:
                opens -= 1

        result += opens

        return result
