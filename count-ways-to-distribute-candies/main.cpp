class Solution {
    const int mod = 1e9 + 7;

   public:
    int waysToDistribute(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = min(i, k); j > 0; --j) {
                if (i == j) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = ((long long)j * dp[i - 1][j] % mod + dp[i - 1][j - 1]) % mod;
                }
            }
        }
        return dp[n][k];
    }
};

class Solution {
    const int mod = 1e9 + 7;
    
   public:
    int waysToDistribute(int n, int k) {
        vector<int> dp(k + 1, 0);
        for (int i = 1; i <= n; ++i) {
             for (int j = min(i, k); j > 0; --j) {
                 if (i == j) {
                     dp[j] = 1;
                 } else {
                     dp[j] = ((long long)j * dp[j] % mod + dp[j - 1]) % mod;
                 }
             }
        }
        return dp[k];
    }
};
