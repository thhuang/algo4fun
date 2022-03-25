#include <epi/generic_test.h>
#include <epi/timed_executor.h>

#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

void FillSurroundedRegions(vector<vector<char>>* board_ptr) {
    auto& mat = *board_ptr;
    int n = mat.size();
    int m = mat.front().size();
    const vector<tuple<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    function<void(int, int)> search = [&](int i, int j) -> void {
        if (i < 0 || i >= n || j < 0 || j >= m) return;
        if (mat[i][j] != 'W') return;

        mat[i][j] = 'S';

        for (auto [di, dj] : directions) search(i + di, j + dj);
    };

    for (int i = 0; i < n; ++i) search(i, 0), search(i, m - 1);
    for (int j = 0; j < m; ++j) search(0, j), search(n - 1, j);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 'W') {
                mat[i][j] = 'B';
                continue;
            }
            if (mat[i][j] == 'S') {
                mat[i][j] = 'W';
                continue;
            }
        }
    }
}

vector<vector<string>> FillSurroundedRegionsWrapper(
    TimedExecutor& executor, vector<vector<string>> board) {
    vector<vector<char>> char_vector;
    char_vector.resize(board.size());
    for (int i = 0; i < board.size(); i++) {
        for (const string& s : board[i]) {
            if (s.size() != 1) {
                throw runtime_error("String size is not 1");
            }
            char_vector[i].push_back(s[0]);
        }
    }

    executor.Run([&] { FillSurroundedRegions(&char_vector); });

    board.clear();
    board.resize(char_vector.size(), {});
    for (int i = 0; i < board.size(); i++) {
        for (char c : char_vector[i]) {
            board[i].emplace_back(1, c);
        }
    }

    return board;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "board"};
    return GenericTestMain(args, "data.tsv", &FillSurroundedRegionsWrapper,
                           DefaultComparator{}, param_names);
}
