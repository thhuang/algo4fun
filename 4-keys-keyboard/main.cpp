class Solution {
   public:
    int maxA(int n) {
        vector<int> dp(n + 1);
        for (int i = 0; i <= n; ++i) {
            dp[i] = i;
            for (int j = 0; j < i - 3; ++j) {
                dp[i] = max(dp[i], dp[j] * (i - j - 1));
            }
        }
        return dp[n];
    }
};
