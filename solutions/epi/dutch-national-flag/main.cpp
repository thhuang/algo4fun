#include <epi/generic_test.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>

#include <array>
#include <vector>
using namespace std;

enum class Color { kRed, kWhite, kBlue };

void DutchFlagPartition(int pivot_index, vector<Color>* vec_ptr) {
    auto& vec = *vec_ptr;
    auto pivot = vec[pivot_index];

    for (int i = 0, l = 0, r = vec.size() - 1; i <= r; ++i) {
        if (vec[i] == pivot) continue;
        if (vec[i] < pivot) {
            swap(vec[l++], vec[i]);
            continue;
        }
        swap(vec[r--], vec[i--]);
    }
}

void DutchFlagPartitionWrapper(TimedExecutor& executor, const vector<int>& A,
                               int pivot_idx) {
    vector<Color> colors;
    colors.resize(A.size());
    array<int, 3> count = {0, 0, 0};
    for (size_t i = 0; i < A.size(); i++) {
        count[A[i]]++;
        colors[i] = static_cast<Color>(A[i]);
    }
    Color pivot = colors[pivot_idx];

    executor.Run([&] { DutchFlagPartition(pivot_idx, &colors); });

    int i = 0;
    while (i < colors.size() && colors[i] < pivot) {
        count[static_cast<int>(colors[i])]--;
        ++i;
    }

    while (i < colors.size() && colors[i] == pivot) {
        count[static_cast<int>(colors[i])]--;
        ++i;
    }

    while (i < colors.size() && colors[i] > pivot) {
        count[static_cast<int>(colors[i])]--;
        ++i;
    }

    if (i != colors.size()) {
        throw TestFailure("Not partitioned after " + to_string(i) +
                          "th element");
    } else if (count != array<int, 3>{0, 0, 0}) {
        throw TestFailure("Some elements are missing from original array");
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "A", "pivot_idx"};
    return GenericTestMain(args, "data.tsv", &DutchFlagPartitionWrapper,
                           DefaultComparator{}, param_names);
}
