class Solution:

    def numWays(self, n: int, k: int) -> int:
        same, diff = 0, 1
        for _ in range(n - 1):
            same, diff = diff, (k - 1) * (same + diff)
        return (same + diff) * k
