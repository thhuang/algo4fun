class Solution:

    def reverse(self, x: int) -> int:
        sign = 1 if x > 0 else -1
        x *= sign

        s = str(x)[::-1]
        v = int(s) * sign

        if v < -2**31 or 2**31 - 1 < v:
            return 0
        return v
