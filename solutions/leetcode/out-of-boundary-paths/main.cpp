class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    const int mod = 1e9 + 7;

   public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(
            maxMove + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        for (int mv = 1; mv <= maxMove; ++mv) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (auto [di, dj] : directions) {
                        int ii = i + di;
                        int jj = j + dj;
                        if (ii < 0 || ii >= m || jj < 0 || jj >= n) {
                            ++dp[mv][i][j];
                        } else {
                            dp[mv][i][j] += dp[mv - 1][ii][jj];
                        }
                        dp[mv][i][j] %= mod;
                    }
                }
            }
        }
        return dp[maxMove][startRow][startColumn];
    }
};

class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    const int mod = 1e9 + 7;

   public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int mv = 1; mv <= maxMove; ++mv) {
            vector<vector<int>> new_dp(m, vector<int>(n, 0));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (auto [di, dj] : directions) {
                        int ii = i + di;
                        int jj = j + dj;
                        if (ii < 0 || ii >= m || jj < 0 || jj >= n) {
                            ++new_dp[i][j];
                        } else {
                            new_dp[i][j] += dp[ii][jj];
                        }
                        new_dp[i][j] %= mod;
                    }
                }
            }
            dp = move(new_dp);
        }
        return dp[startRow][startColumn];
    }
};
