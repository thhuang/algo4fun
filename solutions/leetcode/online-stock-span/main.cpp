class StockSpanner {
    struct PriceSpan {
        int price, span;
    };

    vector<PriceSpan> desc;

   public:
    int next(int price) {
        int span = 1;
        while (!desc.empty() && desc.back().price <= price) {
            span += desc.back().span;
            desc.pop_back();
        }
        desc.push_back({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
