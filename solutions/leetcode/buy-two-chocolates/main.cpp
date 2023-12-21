class Solution {
   public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int mn = prices[0] + prices[1];
        if (mn <= money) {
            return money - mn;
        }
        return money;
    }
};
