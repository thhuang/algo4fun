class Solution {
   public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int result = 0;
        for (int c : costs) {
            if (c > coins) break;
            ++result;
            coins -= c;
        }
        return result;
    }
};
