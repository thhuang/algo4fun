#include <epi/generic_test.h>

#include <algorithm>
using namespace std;

double BuyAndSellStockOnce(const vector<double>& prices) {
    if (empty(prices)) return 0.0;

    double max_profit = 0.0;
    double curr_min = prices[0];
    for (auto price : prices) {
        curr_min = min(curr_min, price);
        max_profit = max(max_profit, price - curr_min);
    }

    return max_profit;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"prices"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &BuyAndSellStockOnce,
                           DefaultComparator{}, param_names);
}
