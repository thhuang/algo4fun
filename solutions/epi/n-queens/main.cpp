#include <epi/generic_test.h>

#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

vector<vector<int>> NQueens(int n) {
    vector<vector<int>> result;
    vector<bool> col(n, false);
    vector<bool> diag0(n * 2 - 1, false);
    vector<bool> diag1(n * 2 - 1, false);

    vector<int> positions;
    function<void(int)> search = [&](int i) {
        if (i == n) {
            result.push_back(positions);
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (col[j] || diag0[i + j] || diag1[i + n - j - 1]) continue;

            col[j] = diag0[i + j] = diag1[i + n - j - 1] = true;
            positions.emplace_back(j);

            search(i + 1);

            col[j] = diag0[i + j] = diag1[i + n - j - 1] = false;
            positions.pop_back();
        }
    };

    search(0);

    return result;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"n"};
    return GenericTestMain(args, "data.tsv", &NQueens, UnorderedComparator{},
                           param_names);
}
