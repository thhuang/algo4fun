#include <epi/generic_test.h>
using namespace std;

int Divide(int x, int y) {
    int res = 0;
    int power = 31;
    while (x >= y) {
        auto y_power = static_cast<long long>(y) << power;
        if (y_power > x) {
            --power;
            continue;
        }
        x -= y_power;
        res += 1 << power;
    }

    return res;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"x", "y"};
    return GenericTestMain(args, "data.tsv", &Divide, DefaultComparator{},
                           param_names);
}
