class Solution:

    def findTheWinner(self, n: int, k: int) -> int:

        def solve(n, k):
            if n == 1:
                return 0
            return (solve(n - 1, k) + k) % n

        return solve(n, k) + 1
