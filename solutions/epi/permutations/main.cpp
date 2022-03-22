#include <epi/generic_test.h>

#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> Permutations(vector<int> A) {
    vector<vector<int>> result;
    function<void(int)> search = [&](int i) {
        if (i == size(A)) {
            result.emplace_back(A);
            return;
        }

        for (int j = i; j < size(A); ++j) {
            swap(A[i], A[j]);
            search(i + 1);
            swap(A[i], A[j]);
        }
    };

    search(0);
    return result;
}

int main(int argc, char *argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A"};
    return GenericTestMain(args, "data.tsv", &Permutations,
                           UnorderedComparator{}, param_names);
}
