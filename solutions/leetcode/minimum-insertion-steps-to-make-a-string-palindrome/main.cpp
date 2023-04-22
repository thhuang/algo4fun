class Solution {
   public:
    int minInsertions(string s) {
        int n = s.size();

        vector dp(n, vector<int>(n, n));
        for (int i = 0; i < n; ++i) dp[i][i] = 0;
        for (int i = 0; i < n - 1; ++i) {
            dp[i][i + 1] = (s[i] == s[i + 1]) ? 0 : 1;
        }

        for (int d = 2; d < n; ++d) {
            for (int l = 0; l + d < n; ++l) {
                int r = l + d;
                if (s[l] == s[r]) dp[l][r] = dp[l + 1][r - 1];
                dp[l][r] = min(dp[l][r], 1 + min(dp[l + 1][r], dp[l][r - 1]));
            }
        }

        return dp.front().back();
    }
};
