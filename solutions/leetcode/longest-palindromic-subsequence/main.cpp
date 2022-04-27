class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int l = 1; l <= n; ++l) {
            for (int i = 0; i + l - 1 < n; ++i) {
                int j = i + l - 1;

                if (i == j) {
                    dp[i][j] = 1;
                    continue;
                }

                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                    continue;
                }

                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][n - 1];
    }
};

class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n <= 1) return n;

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) dp[i][i] = 1;
        for (int i = 0; i + 1 < n; ++i) dp[i][i + 1] = s[i] == s[i + 1] ? 2 : 1;
        for (int d = 3; d <= n; ++d) {
            for (int l = 0; l + d - 1 < n; ++l) {
                int r = l + d - 1;
                if (s[l] == s[r]) {
                    dp[l][r] = dp[l + 1][r - 1] + 2;
                } else {
                    dp[l][r] = max(dp[l][r - 1], dp[l + 1][r]);
                }
            }
        }

        return dp.front().back();
    }
};
