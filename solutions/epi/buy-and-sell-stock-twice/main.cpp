#include <epi/generic_test.h>
using namespace std;

double BuyAndSellStockTwice(const vector<double>& prices) {
    if (empty(prices)) return 0.0;
    vector<double> profit(prices.size(), 0.0);

    double curr_max_profit = 0.0;
    double curr_min_price = prices.front();
    for (int i = 0; i < prices.size(); ++i) {
        curr_min_price = min(curr_min_price, prices[i]);
        curr_max_profit = max(curr_max_profit, prices[i] - curr_min_price);
        profit[i] = curr_max_profit;
    }

    double max_profit = 0.0;
    curr_max_profit = 0.0;
    curr_min_price = prices.back();
    for (int i = prices.size() - 1; ~i; --i) {
        curr_min_price = min(curr_min_price, -prices[i]);
        curr_max_profit = max(curr_max_profit, -prices[i] - curr_min_price);
        max_profit = max(max_profit, profit[i] + curr_max_profit);
    }

    return max_profit;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"prices"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &BuyAndSellStockTwice,
                           DefaultComparator{}, param_names);
}
