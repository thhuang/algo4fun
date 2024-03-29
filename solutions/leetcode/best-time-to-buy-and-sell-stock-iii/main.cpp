class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        struct DP {
            int bought1, sold1, bought2, sold2;
        };

        DP dp{numeric_limits<int>::min(), 0, numeric_limits<int>::min(), 0};

        for (int v : prices) {
            dp = {max(dp.bought1, -v), max(dp.sold1, dp.bought1 + v),
                  max(dp.bought2, dp.sold1 - v), max(dp.sold2, dp.bought2 + v)};
        }

        return dp.sold2;
    }
};

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        struct {
            int hold1, sold1, hold2, sold2;
        } dp = {-prices[0], 0, -prices[0], 0};

        for (int v : prices) {
            dp = {
                max(dp.hold1, -v),
                max(dp.sold1, dp.hold1 + v),
                max(dp.hold2, dp.sold1 - v),
                max(dp.sold2, dp.hold2 + v),
            };
        }

        return dp.sold2;
    }
};
