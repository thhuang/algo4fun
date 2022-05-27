class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        struct DP {
            int stock, cash, cooldown;
        };

        DP dp = {-prices.front(), 0, 0};
        for (int v : prices) {
            dp = {max(dp.stock, dp.cash - v), max(dp.cash, dp.cooldown),
                  max(dp.cooldown, dp.stock + v)};
        }

        return dp.cooldown;
    }
};
