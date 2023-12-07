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
