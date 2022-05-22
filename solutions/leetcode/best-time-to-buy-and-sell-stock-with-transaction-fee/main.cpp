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

class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        struct DP {
            int hold;
            int sold;
        };

        DP dp = {-prices[0], 0};
        for (int i = 1; i < prices.size(); ++i) {
            dp = {max(dp.hold, dp.sold - prices[i]),
                  max(dp.sold, dp.hold + prices[i] - fee)};
        }

        return dp.sold;
    }
};

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
