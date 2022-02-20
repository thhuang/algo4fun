#include <epi/generic_test.h>

#include <functional>
#include <queue>
#include <vector>
using namespace std;

vector<int> SortApproximatelySortedData(
    vector<int>::const_iterator sequence_begin,
    const vector<int>::const_iterator& sequence_end, int k) {
    vector<int> result;
    priority_queue<int, vector<int>, greater<>> min_heap;

    for (auto iter = sequence_begin; iter != sequence_end; ++iter) {
        min_heap.emplace(*iter);
        if (size(min_heap) <= k) continue;

        result.emplace_back(min_heap.top());
        min_heap.pop();
    }

    while (!empty(min_heap)) {
        result.emplace_back(min_heap.top());
        min_heap.pop();
    }

    return result;
}
vector<int> SortApproximatelySortedDataWrapper(const vector<int>& sequence,
                                               int k) {
    return SortApproximatelySortedData(cbegin(sequence), cend(sequence), k);
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"sequence", "k"};
    return GenericTestMain(args, "data.tsv",
                           &SortApproximatelySortedDataWrapper,
                           DefaultComparator{}, param_names);
}
