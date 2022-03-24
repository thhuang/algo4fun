#include <epi/generic_test.h>
using namespace std;

const array<int, 6> coins = {100, 50, 25, 10, 5, 1};

int ChangeMaking(int cents) {
    int num_coins = 0;
    for (int c : coins) {
        if (cents == 0) break;

        num_coins += cents / c;
        cents %= c;
    }

    return num_coins;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"cents"};
    return GenericTestMain(args, "data.tsv", &ChangeMaking, DefaultComparator{},
                           param_names);
}
