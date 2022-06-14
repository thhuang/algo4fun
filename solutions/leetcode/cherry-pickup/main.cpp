class Solution {
   public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        vector<vector<vector<int>>> dp(
            m + n - 1, vector<vector<int>>(m, vector<int>(m, -1)));
        dp[0][0][0] = grid[0][0];
        for (int s = 1; s < m + n - 1; ++s) {
            for (int r1 = max(0, s - n + 1); r1 < m && r1 <= s; ++r1) {
                for (int r2 = r1; r2 < m && r2 <= s; ++r2) {
                    int c1 = s - r1;
                    int c2 = s - r2;
                    if (grid[r1][c1] == -1 || grid[r2][c2] == -1) continue;

                    int v = -1;
                    if (r1 > 0 && r2 > 0) v = max(v, dp[s - 1][r1 - 1][r2 - 1]);
                    if (r1 > 0 && s - r2 > 0) v = max(v, dp[s - 1][r1 - 1][r2]);
                    if (s - r1 > 0 && r2 > 0) v = max(v, dp[s - 1][r1][r2 - 1]);
                    if (s - r1 > 0 && s - r2 > 0) v = max(v, dp[s - 1][r1][r2]);
                    if (v == -1) continue;

                    v += grid[r1][c1];
                    if (r1 != r2 || c1 != c2) v += grid[r2][c2];

                    dp[s][r1][r2] = v;
                }
            }
        }

        int result = dp.back().back().back();
        return ~result ? result : 0;
    }
};
