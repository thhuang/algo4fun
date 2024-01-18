func climbStairs(n int) int {
	dp := []int{1, 1}
	for i := 2; i <= n; i++ {
		dp[0], dp[1] = dp[1], dp[0]+dp[1]
	}
	return dp[1]
}
