class Solution:

    def minimumOneBitOperations(self, n: int) -> int:
        sign = 1
        b = 2
        result = 0
        while n > 0:
            if n % 2 == 1:
                result += (b - 1) * sign
                sign = -sign
            b <<= 1
            n >>= 1
        return result if sign < 0 else -result
