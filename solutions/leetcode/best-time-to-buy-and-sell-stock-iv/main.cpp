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

class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0 || k == 0) return 0;

        vector<int> dp(k * 2, 0);
        for (int i = 0; i < dp.size(); i += 2) dp[i] = -prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            for (int j = dp.size() - 1; j >= 1; --j) {
                if (j % 2 == 0) {
                    dp[j] = max(dp[j], dp[j - 1] - prices[i]);
                } else {
                    dp[j] = max(dp[j], dp[j - 1] + prices[i]);
                }
            }
            dp[0] = max(dp[0], -prices[i]);
        }

        return dp.back();
    }
};
