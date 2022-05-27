class Solution {
   public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon.front().size();

        vector<vector<int>> dp(m, vector<int>(n, numeric_limits<int>::max()));
        dp.back().back() = max(0, -dungeon.back().back());
        for (int i = m - 1; ~i; --i) {
            for (int j = n - 1; ~j; --j) {
                if (i + 1 < m)
                    dp[i][j] =
                        min(dp[i][j], max(0, dp[i + 1][j] - dungeon[i][j]));
                if (j + 1 < n)
                    dp[i][j] =
                        min(dp[i][j], max(0, dp[i][j + 1] - dungeon[i][j]));
            }
        }

        return max(0, dp.front().front()) + 1;
    }
};
