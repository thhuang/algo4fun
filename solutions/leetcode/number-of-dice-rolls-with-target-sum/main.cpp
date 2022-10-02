class Solution {
    const int mod = 1e9 + 7;

   public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; ++i) {
            vector<int> new_dp(target + 1, 0);
            for (int j = target; j >= 1; --j) {
                for (int v = 1; v <= k; ++v) {
                    if (j - v < 0) continue;
                    if (dp[j - v] == 0) continue;
                    new_dp[j] = ((long long)new_dp[j] + dp[j - v]) % mod;
                }
            }
            dp = move(new_dp);
        }

        return dp.back();
    }
};
