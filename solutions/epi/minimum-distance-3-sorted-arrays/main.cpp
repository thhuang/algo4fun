#include <epi/generic_test.h>

#include <limits>
#include <map>
#include <vector>
using namespace std;

int FindClosestElementsInSortedArrays(
    const vector<vector<int>>& sorted_arrays) {
    struct IterEnd {
        vector<int>::const_iterator iter, end;
    };

    multimap<int, IterEnd> elements;
    for (const auto& v : sorted_arrays)
        elements.insert({v.front(), {begin(v), end(v)}});

    int min_dist = numeric_limits<int>::max();
    while (true) {
        int min_val = cbegin(elements)->first;
        int max_val = crbegin(elements)->first;
        min_dist = min(min_dist, max_val - min_val);

        auto next_min = next(cbegin(elements)->second.iter);
        auto next_end = cbegin(elements)->second.end;
        if (next_min == next_end) return min_dist;

        elements.erase(cbegin(elements));
        elements.insert({*next_min, {next_min, next_end}});
    }

    return min_dist;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"sorted_arrays"};
    return GenericTestMain(args, "data.tsv", &FindClosestElementsInSortedArrays,
                           DefaultComparator{}, param_names);
}
