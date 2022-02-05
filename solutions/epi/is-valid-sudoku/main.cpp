#include <epi/generic_test.h>

#include <vector>
using namespace std;

bool HasDuplicate(int rb, int re, int cb, int ce,
                  const vector<vector<int>>& partial_assignment) {
    vector<bool> exists(10);
    for (int i = rb; i < re; ++i) {
        for (int j = cb; j < ce; ++j) {
            int val = partial_assignment[i][j];
            if (val == 0) continue;
            if (exists[val]) return true;
            exists[val] = 1;
        }
    }
    return false;
}

// Check if a partially filled matrix has any conflicts.
bool IsValidSudoku(const vector<vector<int>>& partial_assignment) {
    for (int i = 0; i < 9; ++i) {
        // check rows
        if (HasDuplicate(i, i + 1, 0, 9, partial_assignment)) return false;

        // check columns
        if (HasDuplicate(0, 9, i, i + 1, partial_assignment)) return false;

        // check blocks
        int rb = (i / 3) * 3;  // 0,0,0,3,3,3,6,6,6
        int re = rb + 3;
        int cb = (i % 3) * 3;  // 0,3,6,0,3,6,0,3,6
        int ce = cb + 3;
        if (HasDuplicate(rb, re, cb, ce, partial_assignment)) return false;
    }

    return true;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"partial_assignment"};
    return GenericTestMain(args, "data.tsv", &IsValidSudoku,
                           DefaultComparator{}, param_names);
}
