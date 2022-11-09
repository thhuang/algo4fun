class StockSpanner {
    vector<pair<int, int>> stocks;

   public:
    StockSpanner() {}

    int next(int price) {
        int result = 1;
        while (!stocks.empty() && stocks.back().first <= price) {
            result += stocks.back().second;
            stocks.pop_back();
        }
        stocks.push_back({price, result});
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
