class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<pair<int, char>>> dp(
            n, vector<pair<int, char>>(n, {0, ' '}));
        for (int i = 0; i + 1 < n; ++i) {
            if (s[i] == s[i + 1]) dp[i][i + 1] = {2, s[i]};
        }

        for (int d = 3; d <= n; ++d) {
            for (int l = 0; l + d - 1 < n; ++l) {
                int r = l + d - 1;
                if (s[l] == s[r] && s[l] != dp[l + 1][r - 1].second) {
                    dp[l][r] = {dp[l + 1][r - 1].first + 2, s[l]};
                } else if (dp[l + 1][r].first > dp[l][r - 1].first) {
                    dp[l][r] = dp[l + 1][r];
                } else {
                    dp[l][r] = dp[l][r - 1];
                }
            }
        }

        return dp[0][n - 1].first;
    }
};
