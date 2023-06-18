class Solution {
    struct DP {
        int hold, sold;
    };

   public:
    int maxProfit(vector<int>& prices, int fee) {
        DP dp{-prices[0], 0};
        for (int v : prices) {
            dp = {max(dp.hold, dp.sold - v), max(dp.sold, dp.hold + v - fee)};
        }
        return dp.sold;
    }
};
