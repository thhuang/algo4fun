class Solution:

    def cherryPickup(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[-inf] * n for _ in range(n)]
        dp[0][-1] = grid[0][0] + grid[0][-1]

        for i in range(1, m):
            dp_new = [[
                grid[i][a] if a == b else grid[i][a] + grid[i][b]
                for b in range(n)
            ] for a in range(n)]

            for a in range(n):
                for b in range(n):
                    prev = -inf
                    for da in (-1, 0, 1):
                        for db in (-1, 0, 1):
                            aa, bb = a + da, b + db
                            if aa < 0 or n <= aa or bb < 0 or n <= bb:
                                continue
                            prev = max(prev, dp[a + da][b + db])

                    dp_new[a][b] += prev

            dp = dp_new

        return max((max(r) for r in dp))
