class Solution {
    const int mod = 1e9 + 7;

   public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid.front().size();

        vector<vector<vector<long>>> dp(
            m, vector<vector<long>>(n, vector<long>(k, 0)));
        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i - 1 >= 0) {
                    for (int v = 0; v < k; ++v) {
                        dp[i][j][(v + grid[i][j]) % k] += dp[i - 1][j][v];
                        dp[i][j][(v + grid[i][j]) % k] %= mod;
                    }
                }
                if (j - 1 >= 0) {
                    for (int v = 0; v < k; ++v) {
                        dp[i][j][(v + grid[i][j]) % k] += dp[i][j - 1][v];
                        dp[i][j][(v + grid[i][j]) % k] %= mod;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};
