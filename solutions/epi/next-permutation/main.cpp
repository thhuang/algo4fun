#include <epi/generic_test.h>
using namespace std;

vector<int> NextPermutation(vector<int> perm) {
    int l = -1;
    for (int i = perm.size() - 2; i >= 0; --i) {
        if (perm[i] < perm[i + 1]) {
            l = i;
            break;
        }
    }
    if (l == -1) {
        return {};
    }

    int r = perm.size();
    for (int i = perm.size() - 1; i > l; --i) {
        if (perm[l] < perm[i]) {
            r = i;
            break;
        }
    }

    swap(perm[l], perm[r]);

    reverse(perm.begin() + l + 1, perm.end());

    return perm;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"perm"};
    return GenericTestMain(args, "data.tsv", &NextPermutation,
                           DefaultComparator{}, param_names);
}
