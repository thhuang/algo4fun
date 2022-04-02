class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        if (size(prices) < 2) return 0;

        struct DP {
            int cash, stock;
        };

        DP dp = {0, -prices[0]};
        for (int i = 1; i < size(prices); ++i) {
            dp = {max(dp.cash, dp.stock + prices[i] - fee),
                  max(dp.cash - prices[i], dp.stock)};
        }

        return max(dp.cash, dp.stock);
    }
};
