func rob(nums []int) int {
	dp := [2]int{0, nums[0]}
	for i := 1; i < len(nums); i++ {
		dp[0], dp[1] = dp[1], max(dp[1], dp[0]+nums[i])
	}
	return dp[1]
}
