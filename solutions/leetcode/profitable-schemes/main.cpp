class Solution {
    const int mod = 1e9 + 7;

   public:
    int profitableSchemes(int n, int minProfit, vector<int>& group,
                          vector<int>& profit) {
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        for (auto& r : dp) r[0] = 1;

        for (int i = 0; i < group.size(); ++i) {
            int g = group[i], p = profit[i];
            for (int j = n; j - g >= 0; --j) {
                for (int k = 0; k <= minProfit; ++k) {
                    int new_p = min(k + p, minProfit);
                    dp[j][new_p] =
                        ((long long)dp[j][new_p] + dp[j - g][k]) % mod;
                }
            }
        }

        return dp.back().back();
    }
};
