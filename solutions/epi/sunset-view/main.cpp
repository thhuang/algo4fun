#include <epi/generic_test.h>

#include <algorithm>
using namespace std;

vector<int> ExamineBuildingsWithSunset(
    vector<int>::const_iterator sequence_begin,
    const vector<int>::const_iterator& sequence_end) {
    vector<vector<int>::const_iterator> buildings;
    for (auto iter = sequence_begin; iter != sequence_end; ++iter) {
        while (!buildings.empty() && *buildings.back() <= *iter)
            buildings.pop_back();
        buildings.push_back(iter);
    }

    vector<int> res;
    transform(rbegin(buildings), rend(buildings), back_inserter(res),
              [&](auto iter) { return iter - sequence_begin; });

    return res;
}

vector<int> ExamineBuildingsWithSunsetWrapper(const vector<int>& sequence) {
    return ExamineBuildingsWithSunset(cbegin(sequence), cend(sequence));
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"sequence"};
    return GenericTestMain(args, "data.tsv", &ExamineBuildingsWithSunsetWrapper,
                           DefaultComparator{}, param_names);
}
