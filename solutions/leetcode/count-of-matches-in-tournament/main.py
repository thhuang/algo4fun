class Solution:

    def numberOfMatches(self, n: int) -> int:
        result = 0
        while n > 1:
            result += n // 2
            if n % 2 == 1:
                n += 1
            n //= 2
        return result
