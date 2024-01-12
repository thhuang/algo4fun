class Solution:

    def uniquePaths(self, m: int, n: int) -> int:
        s = (m + n - 2)
        mn = min(m - 1, n - 1)
        result = 1
        for i in range(1, mn + 1):
            result *= s
            result /= i
            s -= 1
        return int(result)
