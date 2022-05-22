class Solution {
   public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        if (stockPrices.size() < 2) return 0;
        sort(stockPrices.begin(), stockPrices.end());

        int count = 1;
        long dx = stockPrices[0][0] - stockPrices[1][0];
        long dy = stockPrices[0][1] - stockPrices[1][1];

        for (int i = 2; i < stockPrices.size(); ++i) {
            long new_dx = stockPrices[i - 1][0] - stockPrices[i][0];
            long new_dy = stockPrices[i - 1][1] - stockPrices[i][1];

            if (dx * new_dy == new_dx * dy) continue;

            dx = new_dx, dy = new_dy;
            ++count;
        }

        return count;
    }
};
