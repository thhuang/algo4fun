#include <epi/generic_test.h>
using namespace std;

/* long long Gcd(long long x, long long y) { */
/*     if (y > x) swap(x, y); */
/*     return y == 0 ? x : Gcd(y, x % y); */
/* } */

long long Gcd(long long x, long long y) {
    if (y > x) swap(x, y);
    while (y) {
        tie(x, y) = tuple<long, long>{y, x % y};
    }
    return x;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"x", "y"};
    return GenericTestMain(args, "data.tsv", &Gcd, DefaultComparator{},
                           param_names);
}
