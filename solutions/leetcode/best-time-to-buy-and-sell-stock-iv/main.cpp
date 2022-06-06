class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0) return 0;

        struct Transaction {
            int bought = numeric_limits<int>::min();
            int sold = 0;
        };
        vector<Transaction> dp(k + 1);

        for (int v : prices) {
            for (int i = dp.size() - 1; i >= 1; --i) {
                dp[i] = {max(dp[i].bought, dp[i - 1].sold - v),
                         max(dp[i].sold, dp[i].bought + v)};
            }
        }

        return dp.back().sold;
    }
};
