class Solution {
    const int mod = 1e9 + 7;

   public:
    int numWays(vector<string>& words, string target) {
        int m = target.size();
        int n = words.front().size();

        vector cnt(n, vector<int>(26, 0));
        for (int j = 0; j < n; ++j) {
            for (const string& word : words) {
                ++cnt[j][word[j] - 'a'];
            }
        }

        vector dp(m + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= m; ++i) {
            int c = target[i] - 'a';
            for (int j = 0; j < n; ++j) {
                if (i < m) {
                    (dp[i + 1][j + 1] += cnt[j][c] * dp[i][j]) %= mod;
                }
                (dp[i][j + 1] += dp[i][j]) %= mod;
            }
        }

        return dp[m][n];
    }
};
