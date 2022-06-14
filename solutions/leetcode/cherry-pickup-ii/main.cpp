class Solution {
    vector<array<int, 2>> directions = {{-1, -1}, {-1, 0}, {-1, 1},
                                        {0, -1},  {0, 0},  {0, 1},
                                        {1, -1},  {1, 0},  {1, 1}};

   public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][n - 1] = grid[0][0] + grid[0][n - 1];

        for (int r = 0; r < m - 1; ++r) {
            vector<vector<int>> new_dp(n, vector<int>(n, 0));
            for (int c1 = 0; c1 < min(r + 1, n); ++c1) {
                for (int c2 = n - 1; c2 >= max(n - 1 - r, c1); --c2) {
                    for (auto [d1, d2] : directions) {
                        int nc1 = c1 + d1, nc2 = c2 + d2;
                        if (nc1 < 0 || nc1 >= n || nc2 < 0 || nc2 >= n || nc1 > nc2) continue;
                        int v = dp[c1][c2] + grid[r + 1][nc1];
                        if (nc1 != nc2) v += grid[r + 1][nc2];
                        new_dp[nc1][nc2] = max(new_dp[nc1][nc2], v);
                    }
                }
            }
            dp = move(new_dp);
        }

        int result = 0;
        for (const auto& r : dp) {
            for (const auto& v : r) result = max(result, v);
        }
        return result;
    }
};
