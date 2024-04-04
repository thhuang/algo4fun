class Solution:

    def maxDepth(self, s: str) -> int:
        result = 0
        curr = 0
        for c in s:
            if c == "(":
                curr += 1
            elif c == ")":
                curr -= 1
            result = max(result, curr)
        return result
