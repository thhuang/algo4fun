class Solution {
   public:
    int strangePrinter(string s) {
        s.erase(unique(s.begin(), s.end()), s.end());

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, numeric_limits<int>::max()));

        for (int i = 0; i < n; ++i) dp[i][i] = 1;
        for (int d = 2; d <= n; ++d) {
            for (int l = 0; l + d - 1 < n; ++l) {
                int r = l + d - 1;
                for (int m = l + 1; m <= r; ++m) {
                    int v = dp[l][m - 1] + dp[m][r];
                    if (s[l] == s[r]) --v;
                    dp[l][r] = min(dp[l][r], v);
                }
            }
        }

        return dp.front().back();
    }
};
