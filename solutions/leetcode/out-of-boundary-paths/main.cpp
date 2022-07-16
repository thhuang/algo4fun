class Solution {
    const int mod = 1e9 + 7;
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int k = 0; k < maxMove; ++k) {
            vector<vector<int>> new_dp(m, vector<int>(n, 0));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    long long count = 0;
                    for (auto [di, dj] : directions) {
                        int ii = i + di;
                        int jj = j + dj;
                        if (ii < 0 || ii >= m || jj < 0 || jj >= n) {
                            ++count;
                        } else {
                            count += dp[ii][jj];
                        }
                    }
                    new_dp[i][j] = count % mod;
                }
            }
            dp = move(new_dp);
        }

        return dp[startRow][startColumn];
    }
};
