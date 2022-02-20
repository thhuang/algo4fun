#include <epi/generic_test.h>

#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

struct Payload {
    vector<int>::const_iterator current;
    vector<int>::const_iterator end;

    bool operator>(const Payload other) const {
        return *current > *other.current;
    }

    void next() { ++current; }

    bool empty() { return current == end; }
};

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
    auto heap = priority_queue<Payload, vector<Payload>, greater<>>();

    for (const vector<int>& arr : sorted_arrays) {
        if (!empty(arr)) heap.push({cbegin(arr), cend(arr)});
    }

    vector<int> result;
    while (!empty(heap)) {
        auto payload = heap.top();
        heap.pop();

        result.emplace_back(*payload.current);

        payload.next();
        if (!payload.empty()) heap.push(payload);
    }

    return result;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"sorted_arrays"};
    return GenericTestMain(args, "data.tsv", &MergeSortedArrays,
                           DefaultComparator{}, param_names);
}
