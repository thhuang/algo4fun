class Solution:

    def checkValidString(self, s: str) -> bool:
        mn = 0
        mx = 0
        for c in s:
            if c == "(":
                mn += 1
                mx += 1
            elif c == ")":
                mn -= 1
                mx -= 1
            else:  # c == "*"
                mn -= 1
                mx += 1
            if mx < 0:
                return False
            mn = max(mn, 0)
        return mn == 0
