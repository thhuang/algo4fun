#include <epi/generic_test.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>

#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>
using namespace std;

bool IsValid(vector<vector<int>>& board, int i, int j, int x) {
    for (int k = 0; k < 9; ++k) {
        if (board[i][k] == x) return false;
        if (board[k][j] == x) return false;
    }

    for (int row = i - i % 3; row < i - i % 3 + 3; ++row) {
        for (int col = j - j % 3; col < j - j % 3 + 3; ++col) {
            if (board[row][col] == x) return false;
        }
    }

    return true;
}

array<int, 2> NextPos(int i, int j) {
    if (i < 8) return {i + 1, j};
    return {0, j + 1};
}

bool FillBoard(vector<vector<int>>& board, int i, int j) {
    if (j == 9) return true;

    if (board[i][j]) {
        auto next_pos = NextPos(i, j);
        return FillBoard(board, next_pos[0], next_pos[1]);
    }

    for (int x = 1; x <= 9; ++x) {
        if (!IsValid(board, i, j, x)) continue;

        board[i][j] = x;
        auto next_pos = NextPos(i, j);
        if (FillBoard(board, next_pos[0], next_pos[1])) return true;
        board[i][j] = 0;
    }

    return false;
}

bool SolveSudoku(vector<vector<int>>* partial_assignment) {
    return FillBoard(*partial_assignment, 0, 0);
}

vector<int> GatherColumn(const vector<vector<int>>& data, size_t i) {
    vector<int> result;
    for (auto& row : data) {
        result.push_back(row[i]);
    }
    return result;
}

vector<int> GatherSquareBlock(const vector<vector<int>>& data,
                              size_t block_size, size_t n) {
    vector<int> result;
    size_t block_x = n % block_size;
    size_t block_y = n / block_size;
    for (size_t i = block_x * block_size; i < (block_x + 1) * block_size; i++) {
        for (size_t j = block_y * block_size; j < (block_y + 1) * block_size;
             j++) {
            result.push_back(data[i][j]);
        }
    }

    return result;
}

void AssertUniqueSeq(const vector<int>& seq) {
    vector<bool> seen(seq.size(), false);
    for (auto& x : seq) {
        if (x == 0) {
            throw TestFailure("Cell left uninitialized");
        }
        if (x < 0 || x > seq.size()) {
            throw TestFailure("Cell value out of range");
        }
        if (seen[x - 1]) {
            throw TestFailure("Duplicate value in section");
        }
        seen[x - 1] = true;
    }
}

void SolveSudokuWrapper(TimedExecutor& executor,
                        const vector<vector<int>>& partial_assignment) {
    vector<vector<int>> solved = partial_assignment;

    executor.Run([&] { SolveSudoku(&solved); });

    if (!equal(begin(partial_assignment), end(partial_assignment),
               begin(solved), end(solved), [](auto br, auto cr) {
                   return equal(begin(br), end(br), begin(cr), end(cr),
                                [](int bcell, int ccell) {
                                    return bcell == 0 || bcell == ccell;
                                });
               }))
        throw TestFailure("Initial cell assignment has been changed");

    auto block_size = static_cast<size_t>(sqrt(solved.size()));

    for (size_t i = 0; i < solved.size(); i++) {
        AssertUniqueSeq(solved[i]);
        AssertUniqueSeq(GatherColumn(solved, i));
        AssertUniqueSeq(GatherSquareBlock(solved, block_size, i));
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "partial_assignment"};
    return GenericTestMain(args, "data.tsv", &SolveSudokuWrapper,
                           DefaultComparator{}, param_names);
}
