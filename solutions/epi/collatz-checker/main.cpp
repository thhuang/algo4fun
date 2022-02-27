#include <epi/generic_test.h>

#include <unordered_set>
#include <vector>
using namespace std;

bool TestCollatzConjecture(int n) {
    unordered_set<int> passed = {1, 2};
    for (int i = 3; i <= n; i += 2) {
        int num = i;
        while (passed.emplace(num).second) {
            if (num & 1) {
                num = num * 3 + 1;
            } else {
                num >>= 1;
            }
            if (num == i) return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"n"};
    return GenericTestMain(args, "data.tsv", &TestCollatzConjecture,
                           DefaultComparator{}, param_names);
}
