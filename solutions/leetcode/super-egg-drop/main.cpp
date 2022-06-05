class Solution {
   public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));  // eggs, steps
        for (int j = 0; j <= n; ++j) dp[1][j] = j;

        int result = numeric_limits<int>::max();
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= n; ++j) {
                int v = 1 + dp[i - 1][j - 1] + dp[i][j - 1];
                dp[i][j] = max(dp[i][j], v);
                if (v >= n) {
                    result = min(result, j);
                    break;
                }
            }
        }

        return result;
    }
};
