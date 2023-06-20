class StockSpanner {
    struct priceSpan {
        int price, span;
    };

    vector<priceSpan> priceSpans;

   public:
    int next(int price) {
        int span = 1;
        while (!priceSpans.empty() && priceSpans.back().price <= price) {
            span += priceSpans.back().span;
            priceSpans.pop_back();
        }
        priceSpans.push_back({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
