#include <epi/generic_test.h>

#include <vector>
using namespace std;

int SmallestNonconstructibleValue(vector<int> A) {
    sort(begin(A), end(A));

    int current_max = 0;
    for (int v : A) {
        if (v > current_max + 1) break;
        current_max += v;
    }

    return current_max + 1;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A"};
    return GenericTestMain(args, "data.tsv", &SmallestNonconstructibleValue,
                           DefaultComparator{}, param_names);
}
