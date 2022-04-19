class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (size(prices) < 2) return 0;

        struct Entry {
            int buy, sell, cooldown;
            int maximum() { return max({buy, sell, cooldown}); }
        };

        vector<Entry> dp(size(prices), {-prices[0], 0, 0});
        for (int i = 1; i < size(prices); ++i) {
            dp[i] = {
                max(dp[i - 1].buy + prices[i - 1], dp[i - 1].cooldown) -
                    prices[i],
                max(dp[i - 1].buy, dp[i - 1].sell - prices[i - 1]) + prices[i],
                max(dp[i - 1].sell, dp[i - 1].cooldown)};
        }

        return dp.back().maximum();
    }
};

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (size(prices) < 2) return 0;

        struct DP {
            int buy, sell, cooldown;
        };

        DP dp = {-prices[0], 0, 0};
        for (int i = 1; i < size(prices); ++i) {
            dp = {max(dp.buy + prices[i - 1], dp.cooldown) - prices[i],
                  max(dp.sell - prices[i - 1], dp.buy) + prices[i],
                  max(dp.cooldown, dp.sell)};
        }

        return max({dp.buy, dp.sell, dp.cooldown});
    }
};

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        struct DP {
            int hold, cash, just_sold;
        };

        DP dp = {numeric_limits<int>::min(), 0, 0};
        for (int i = 0; i < prices.size(); ++i) {
            dp = {max(dp.hold, dp.cash - prices[i]), max(dp.cash, dp.just_sold),
                  dp.hold + prices[i]};
        }

        return max(dp.cash, dp.just_sold);
    }
};
