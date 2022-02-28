#include <epi/generic_test.h>

#include <algorithm>
#include <vector>
using namespace std;

int HIndex(vector<int> citations) {
    sort(begin(citations), end(citations), greater<>());

    for (int i = 0; i < size(citations); ++i) {
        int h = i + 1;
        if (citations[i] < h) return h - 1;
    }

    return size(citations);
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"citations"};
    return GenericTestMain(args, "data.tsv", &HIndex, DefaultComparator{},
                           param_names);
}
