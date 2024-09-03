class Solution:

    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1

        inv = n < 0
        n = -n if inv else n

        y = 1
        while n > 0:
            if n & 1 == 1:
                y *= x
            x *= x
            n >>= 1

        return y if not inv else 1 / y
