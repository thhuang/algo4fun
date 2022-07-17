class Solution {
    const int mod = 1e9 + 7;

   public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i <= n; ++i) dp[i][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int r = 0; r <= min(j, i - 1); ++r) {
                    dp[i][j] = ((long long)dp[i][j] + dp[i - 1][j - r]) % mod;
                }
            }
        }
        return dp.back().back();
    }
};

class Solution {
    const int mod = 1e9 + 7;

   public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i <= n; ++i) dp[i][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = ((long long)dp[i][j - 1] + dp[i - 1][j]) % mod;
                if (i - 1 < j)
                    dp[i][j] = ((long long)dp[i][j] + mod - dp[i - 1][j - i]) % mod;
            }
        }
        return dp.back().back();
    }
};

class Solution {
    const int mod = 1e9 + 7;

   public:
    int kInversePairs(int n, int k) {
        vector<int> dp(k + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            vector<int> new_dp(k + 1, 0);
            new_dp[0] = 1;
            for (int j = 1; j <= k; ++j) {
                new_dp[j] = ((long long)new_dp[j - 1] + dp[j]) % mod;
                if (i - 1 < j)
                    new_dp[j] = ((long long)new_dp[j] + mod - dp[j - i]) % mod;
            }
            dp = move(new_dp);
        }

        return dp.back();
    }
};
