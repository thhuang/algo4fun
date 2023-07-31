class Solution {
   public:
    int strangePrinter(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, numeric_limits<int>::max()));
        for (int i = 0; i < n; ++i) dp[i][i] = 1;
        for (int d = 2; d <= n; ++d) {
            for (int l = 0, r = l + d - 1; r < n; ++l, ++r) {
                for (int m = l; m < r; ++m) {
                    int v = dp[l][m] + dp[m + 1][r];
                    if (s[l] == s[r]) --v;
                    dp[l][r] = min(dp[l][r], v);
                }
            }
        }

        return dp[0][n - 1];
    }
};
