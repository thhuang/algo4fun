class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        struct DP {
            int bought, sold;
        };

        DP dp = {-prices.front(), 0};
        for (int v : prices) {
            dp = {max(dp.bought, dp.sold - v),
                  max(dp.sold, dp.bought + v - fee)};
        }

        return dp.sold;
    }
};
