#include <epi/generic_test.h>

#include <tuple>
using namespace std;

int Fibonacci(int n) {
    if (n <= 1) return n;

    int prev2 = 0;
    int prev1 = 1;
    for (int i = 2; i <= n; ++i) {
        tie(prev1, prev2) = tuple<int, int>{prev1 + prev2, prev1};
    }

    return prev1;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"n"};
    return GenericTestMain(args, "data.tsv", &Fibonacci, DefaultComparator{},
                           param_names);
}
