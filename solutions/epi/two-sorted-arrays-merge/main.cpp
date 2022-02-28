#include <epi/generic_test.h>

#include <vector>
using namespace std;

void MergeTwoSortedArrays(vector<int>& A, int m, const vector<int>& B, int n) {
    int p = m + n - 1;
    int i = m - 1;
    int j = n - 1;
    while (~i && ~j) A[p--] = A[i] > B[j] ? A[i--] : B[j--];
    while (~j) A[p--] = B[j--];
}

vector<int> MergeTwoSortedArraysWrapper(vector<int> A, int m,
                                        const vector<int>& B, int n) {
    MergeTwoSortedArrays(A, m, B, n);
    return A;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A", "m", "B", "n"};
    return GenericTestMain(args, "data.tsv", &MergeTwoSortedArraysWrapper,
                           DefaultComparator{}, param_names);
}
