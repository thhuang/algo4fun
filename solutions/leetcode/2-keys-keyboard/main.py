class Solution:

    def minSteps(self, n: int) -> int:
        result = 0
        p = 2
        while p <= n:
            while n % p == 0:
                result += p
                n /= p
            p += 1
        return result
