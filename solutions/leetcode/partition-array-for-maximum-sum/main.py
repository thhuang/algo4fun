class Solution:

    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        dp = [0 for _ in range(n + 1)]
        for l in reversed(range(n)):
            mx = -inf
            for r in range(l, min(n, l + k)):
                mx = max(mx, arr[r])
                dp[l] = max(dp[l], mx * (r - l + 1) + dp[r + 1])
        return dp[0]
