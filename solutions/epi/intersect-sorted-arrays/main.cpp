#include <epi/generic_test.h>

#include <vector>
using namespace std;

vector<int> IntersectTwoSortedArrays(const vector<int>& A,
                                     const vector<int>& B) {
    vector<int> intersection;
    int i = 0, j = 0;
    while (i < size(A) && j < size(B)) {
        if (A[i] < B[j]) {
            ++i;
            continue;
        }
        if (A[i] > B[j]) {
            ++j;
            continue;
        }
        if (size(intersection) && A[i] == intersection.back()) {
            ++i, ++j;
            continue;
        }

        intersection.emplace_back(A[i]);
        ++i, ++j;
    }

    return intersection;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A", "B"};
    return GenericTestMain(args, "data.tsv", &IntersectTwoSortedArrays,
                           DefaultComparator{}, param_names);
}
