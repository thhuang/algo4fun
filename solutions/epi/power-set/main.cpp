#include <epi/generic_test.h>

#include <vector>
using namespace std;

vector<vector<int>> GeneratePowerSet(const vector<int>& input_set) {
    vector<vector<int>> result;

    vector<int> selection;
    function<void(int)> search = [&](int i) {
        if (i == size(input_set)) {
            result.emplace_back(selection);
            return;
        }

        search(i + 1);
        selection.emplace_back(input_set[i]);
        search(i + 1);
        selection.pop_back();
    };

    search(0);
    return result;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"input_set"};
    return GenericTestMain(args, "data.tsv", &GeneratePowerSet,
                           UnorderedComparator{}, param_names);
}
