class Solution {
   public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = size(costs) / 2;
        vector<vector<int>> dp(n + 1,
                               vector<int>(n + 1, numeric_limits<int>::max()));
        int sum_a = 0, sum_b = 0;
        for (int i = 1; i <= n; ++i) {
            sum_a += costs[i - 1][0];
            sum_b += costs[i - 1][1];
            dp[i][0] = sum_a;
            dp[0][i] = sum_b;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = min(dp[i - 1][j] + costs[i + j - 1][0],
                               dp[i][j - 1] + costs[i + j - 1][1]);
            }
        }
        return dp[n][n];
    }
};
