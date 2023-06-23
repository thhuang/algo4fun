class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int mn = prices[0];
        for (int v : prices) {
            result = max(result, v - mn);
            mn = min(mn, v);
        }
        return result;
    }
};
