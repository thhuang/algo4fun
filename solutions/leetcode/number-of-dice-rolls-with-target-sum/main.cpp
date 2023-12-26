class Solution {
    const int mod = 1e9 + 7;

   public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            vector<int> dpNew(target + 1, 0);
            for (int j = 0; j < dp.size(); ++j) {
                for (int r = j + 1; r <= j + k && r < dp.size(); ++r) {
                    (dpNew[r] += dp[j]) %= mod;
                }
            }
            dp = dpNew;
        }
        return dp[target];
    }
};
