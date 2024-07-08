class Solution:

    def findTheWinner(self, n: int, k: int) -> int:

        def solve(n, k):
            if n == 1:
                return 0
            return (solve(n - 1, k) + k) % n

        return solve(n, k) + 1


class Solution:

    def findTheWinner(self, n: int, k: int) -> int:
        dp = 0
        for i in range(1, n):
            dp = (dp + k) % (i + 1)
        return dp + 1
