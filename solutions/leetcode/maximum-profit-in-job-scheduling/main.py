class Solution:

    def jobScheduling(self, startTime: List[int], endTime: List[int],
                      profit: List[int]) -> int:
        n = len(startTime)

        jobs = list(range(n))
        jobs.sort(key=lambda i: endTime[i])

        dp = [0 for _ in range(n)]
        dp[0] = profit[jobs[0]]
        for i in range(1, n):
            k = bisect.bisect_right(
                jobs, startTime[jobs[i]], key=lambda j: endTime[j]) - 1

            dp[i] = dp[i - 1]
            if k >= 0:
                dp[i] = max(dp[i], dp[k] + profit[jobs[i]])
            else:
                dp[i] = max(dp[i], profit[jobs[i]])

        return dp[-1]
