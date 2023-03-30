class Solution {
   public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();

        vector<vector<vector<bool>>> dp(
            n + 1, vector<vector<bool>>(n, vector<bool>(n, false)));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[1][i][j] = s1[i] == s2[j];
            }
        }

        for (int k = 2; k <= n; ++k) {
            for (int i = 0; i + k <= n; ++i) {
                for (int j = 0; j + k <= n; ++j) {
                    for (int a = 1; a < k; ++a) {
                        int b = k - a;
                        bool same = dp[a][i][j] && dp[b][i + a][j + a];
                        bool swapped = dp[a][i][j + b] && dp[b][i + a][j];
                        if (dp[k][i][j] = same || swapped) break;
                    }
                }
            }
        }

        return dp[n][0][0];
    }
};
