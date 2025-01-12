class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        if len(s) % 2 == 1:
            return False

        max_open = 0
        min_open = 0

        for i in range(len(s)):
            if locked[i] == "0":
                max_open += 1
                min_open = max(0, min_open - 1)
            elif s[i] == "(":
                max_open += 1
                min_open += 1
            else:
                max_open -= 1
                min_open = max(0, min_open - 1)
                if min_open > max_open:
                    return False

        return min_open == 0
