#include <epi/generic_test.h>
using namespace std;

void ApplyPermutation(vector<int> perm, vector<int>* vec_ptr) {
    auto& vec = *vec_ptr;
    for (int i = 0; i < vec.size(); ++i) {
        while (i != perm[i]) {
            swap(vec[i], vec[perm[i]]);
            swap(perm[i], perm[perm[i]]);
        }
    }
}

vector<int> ApplyPermutationWrapper(const vector<int>& perm, vector<int> A) {
    ApplyPermutation(perm, &A);
    return A;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"perm", "A"};
    return GenericTestMain(args, "main.cpp", "data.tsv",
                           &ApplyPermutationWrapper, DefaultComparator{},
                           param_names);
}
