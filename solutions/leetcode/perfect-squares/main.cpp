class Solution {
   public:
    int numSquares(int n) {
        vector<int> dp(n + 1, numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int v = 1; i + v * v <= n; ++v) {
                int j = i + v * v;
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }
        return dp[n];
    }
};
