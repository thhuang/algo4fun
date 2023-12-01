class Solution:

    def nextGreaterElement(self, n: int) -> int:
        s = str(n)

        l = len(s) - 2
        while l >= 0 and s[l] >= s[l + 1]:
            l -= 1

        if l == -1:
            return -1

        r = len(s) - 1
        while s[r] <= s[l]:
            r -= 1

        s = s[0:l] + s[r] + "".join(sorted(
            list(s[l + 1:r] + s[l] + s[r + 1:])))

        v = int(s)

        return v if v <= 2**31 - 1 else -1
