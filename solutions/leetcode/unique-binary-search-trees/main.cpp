class Solution {
   public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int l = 0; l < i; ++l) {
                int r = i - l - 1;
                dp[i] += dp[l] * dp[r];
            }
        }
        return dp.back();
    }
};
