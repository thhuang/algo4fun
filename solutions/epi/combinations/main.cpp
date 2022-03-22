#include <epi/generic_test.h>

#include <vector>
using namespace std;

vector<vector<int>> Combinations(int n, int k) {
    vector<vector<int>> result;
    vector<int> selection;

    function<void(int)> search = [&](int i) {
        if (size(selection) == k) {
            result.emplace_back(selection);
            return;
        }

        if (n - i + 1 + size(selection) < k) return;

        search(i + 1);
        selection.emplace_back(i);
        search(i + 1);
        selection.pop_back();
    };

    search(1);
    return result;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"n", "k"};
    return GenericTestMain(args, "data.tsv", &Combinations,
                           UnorderedComparator{}, param_names);
}
