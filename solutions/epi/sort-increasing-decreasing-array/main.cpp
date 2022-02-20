#include <epi/generic_test.h>

#include <deque>
#include <iterator>
#include <queue>
#include <vector>
using namespace std;

vector<int> MergeSortedArrays(const vector<deque<int>>& sorted_arrs);

vector<int> SortKIncreasingDecreasingArray(const vector<int>& A) {
    if (empty(A)) return {};

    vector<deque<int>> sorted_arrs;

    bool is_increasing = true;
    sorted_arrs.push_back({A[0]});
    for (int i = 1; i < size(A); ++i) {
        bool is_new_direction = false;
        if (is_increasing && A[i] < A[i - 1]) is_new_direction = true;
        if (!is_increasing && A[i] > A[i - 1]) is_new_direction = true;

        if (!is_new_direction) {
            is_increasing ? sorted_arrs.back().emplace_back(A[i])
                          : sorted_arrs.back().emplace_front(A[i]);
            continue;
        }

        sorted_arrs.push_back({A[i]});
        is_increasing = !is_increasing;
    }

    return MergeSortedArrays(sorted_arrs);
}

struct Payload {
    deque<int>::const_iterator current;
    deque<int>::const_iterator end;

    bool operator>(const Payload other) const {
        return *current > *other.current;
    }

    void next() { ++current; }

    bool empty() { return current == end; }
};

vector<int> MergeSortedArrays(const vector<deque<int>>& sorted_arrs) {
    auto min_heap = priority_queue<Payload, vector<Payload>, greater<>>();

    for (const auto& arr : sorted_arrs) {
        min_heap.push({cbegin(arr), cend(arr)});
    }

    vector<int> result;
    while (!empty(min_heap)) {
        auto payload = min_heap.top();
        min_heap.pop();

        result.emplace_back(*payload.current);

        payload.next();
        if (!payload.empty()) min_heap.push(payload);
    }

    return result;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A"};
    return GenericTestMain(args, "data.tsv", &SortKIncreasingDecreasingArray,
                           DefaultComparator{}, param_names);
}
