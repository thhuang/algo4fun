#include <epi/generic_test.h>
using namespace std;

bool CanReachEnd(const vector<int>& max_advance_steps) {
    int dist = 0;
    for (int i = 0; i < max_advance_steps.size(); ++i) {
        if (dist < i) return false;
        dist = max(dist, i + max_advance_steps[i]);
    }
    return true;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"max_advance_steps"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &CanReachEnd,
                           DefaultComparator{}, param_names);
}
