class Solution:

    def minimumTotalDistance(self, robot: List[int],
                             factory: List[List[int]]) -> int:
        robot.sort()
        factory.sort()

        quota = [p for p, k in factory for _ in range(k)]

        @lru_cache
        def dp(i, j):
            if i < 0:
                return 0
            if i > j:
                return float('inf')

            skip = dp(i, j - 1)
            match = dp(i - 1, j - 1) + abs(robot[i] - quota[j])

            return min(skip, match)

        return dp(len(robot) - 1, len(quota) - 1)
