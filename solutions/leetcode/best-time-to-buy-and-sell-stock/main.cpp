class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = numeric_limits<int>::max();
        for (int v : prices) {
            min_price = min(min_price, v);
            max_profit = max(max_profit, v - min_price);
        }
        return max_profit;
    }
};
