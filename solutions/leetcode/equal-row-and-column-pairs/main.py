class Solution:

    def equalPairs(self, grid: List[List[int]]) -> int:
        n = len(grid)

        mp = defaultdict(int)
        for row in grid:
            mp[tuple(row)] += 1

        result = 0
        for c in range(n):
            result += mp[tuple([grid[i][c] for i in range(n)])]

        return result
