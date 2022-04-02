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
