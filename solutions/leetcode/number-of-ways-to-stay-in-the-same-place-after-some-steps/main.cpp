class Solution {
    const int mod = 1e9 + 7;

   public:
    int numWays(int steps, int arrLen) {
        int n = min(steps / 2 + 1, arrLen);
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < steps; ++i) {
            vector<int> dpNew = dp;
            for (int j = 0; j < n; ++j) {
                if (0 <= j - 1) (dpNew[j] += dp[j - 1]) %= mod;
                if (j + 1 < n) (dpNew[j] += dp[j + 1]) %= mod;
            }
            dp = dpNew;
        }
        return dp[0];
    }
};
