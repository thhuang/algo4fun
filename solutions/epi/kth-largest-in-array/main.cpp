#include <epi/generic_test.h>

#include <array>
#include <cstdlib>
#include <vector>
using namespace std;

array<int, 2> Partition(vector<int>& vec, int left, int right, int pivot) {
    int target = vec[pivot];
    int p = left, l = left, r = right;
    while (p <= r) {
        if (vec[p] > target) {
            swap(vec[p], vec[l]);
            ++p, ++l;
            continue;
        }
        if (vec[p] < target) {
            swap(vec[p], vec[r]);
            --r;
            continue;
        }
        ++p;
    }

    return {l, p - 1};
}

// The numbering starts from one, i.e., if A = [3, 1, -1, 2] then
// FindKthLargest(1, A) returns 3, FindKthLargest(2, A) returns 2,
// FindKthLargest(3, A) returns 1, and FindKthLargest(4, A) returns -1.
int FindKthLargest(int k, vector<int>* A_ptr) {
    --k;
    vector<int>& vec = *A_ptr;

    int l = 0, r = size(vec) - 1;
    while (true) {
        int pivot = l + rand() % (r - l + 1);
        auto pivot_range = Partition(vec, l, r, pivot);

        if (pivot_range[1] < k) {
            l = pivot_range[1] + 1;
            continue;
        }
        if (pivot_range[0] > k) {
            r = pivot_range[0] - 1;
            continue;
        }
        return vec[pivot_range[0]];
    }

    return 0;
}

int FindKthLargestWrapper(int k, vector<int>& A) {
    return FindKthLargest(k, &A);
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"k", "A"};
    return GenericTestMain(args, "data.tsv", &FindKthLargestWrapper,
                           DefaultComparator{}, param_names);
}
