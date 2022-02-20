#include <epi/generic_test.h>

#include <queue>
#include <vector>
using namespace std;

struct Entry {
    int index;
    int value;

    bool operator<(Entry other) const { return value < other.value; }
};

vector<int> KLargestInBinaryHeap(const vector<int>& A, int k) {
    if (A.empty() || k == 0) return {};

    vector<int> result;
    auto heap = priority_queue<Entry>();

    heap.push({0, A[0]});
    for (int i = 0; i < k; ++i) {
        auto entry = heap.top();
        heap.pop();

        result.emplace_back(entry.value);

        if (int index = entry.index * 2 + 1; index < size(A))
            heap.push({index, A[index]});
        if (int index = entry.index * 2 + 2; index < size(A))
            heap.push({index, A[index]});
    }

    return result;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A", "k"};
    return GenericTestMain(args, "data.tsv", &KLargestInBinaryHeap,
                           UnorderedComparator{}, param_names);
}
