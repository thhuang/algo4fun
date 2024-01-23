func longestPalindromeSubseq(s string) int {
	n := len(s)

	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		dp[i][i] = 1
	}
	for i := 1; i < n; i++ {
		if s[i-1] == s[i] {
			dp[i-1][i] = 2
		} else {
			dp[i-1][i] = 1
		}
	}
	for d := 3; d <= n; d++ {
		for r := d - 1; r < n; r++ {
			l := r - d + 1
			if s[l] == s[r] {
				dp[l][r] = 2 + dp[l+1][r-1]
			} else {
				dp[l][r] = max(dp[l+1][r], dp[l][r-1])
			}
		}
	}
	return dp[0][n-1]
}
