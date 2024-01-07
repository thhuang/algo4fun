class Solution:

    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)

        remain_max = jobDifficulty[:]
        for i in reversed(range(0, n - 1)):
            remain_max[i] = max(jobDifficulty[i], remain_max[i + 1])

        @cache
        def dp(i: int, days_left: int) -> int:
            if days_left == 1:
                return remain_max[i]

            result = inf
            curr_max = 0
            for j in range(i, n - days_left + 1):
                curr_max = max(curr_max, jobDifficulty[j])
                result = min(result, curr_max + dp(j + 1, days_left - 1))

            return result

        result = dp(0, d)

        return result if result < inf else -1


class Solution:

    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)

        remain_max = jobDifficulty[:]
        for i in reversed(range(0, n - 1)):
            remain_max[i] = max(jobDifficulty[i], remain_max[i + 1])

        dp = [[inf] * (d + 1) for _ in range(n + 1)]
        for i in reversed(range(0, n)):
            dp[i][1] = remain_max[i]
            for days_left in range(2, d + 1):
                result = inf
                curr_max = 0
                for j in range(i, n - days_left + 1):
                    curr_max = max(curr_max, jobDifficulty[j])
                    result = min(result, curr_max + dp[j + 1][days_left - 1])
                dp[i][days_left] = result

        return dp[0][d] if dp[0][d] < inf else -1
