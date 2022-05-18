class Solution {
   public:
    void solveSudoku(vector<vector<char>>& board) {
        function<bool(int, int, int, int)> check =
            [&board](int li, int ri, int lj, int rj) -> bool {
            bitset<9> vis;
            for (int i = li; i < ri; ++i) {
                for (int j = lj; j < rj; ++j) {
                    if (board[i][j] == '.') continue;
                    int v = board[i][j] - '0';
                    if (vis[v]) return false;
                    vis[v] = true;
                }
            }
            return true;
        };

        function<bool(int, int)> is_valid = [&board, &check](int i,
                                                             int j) -> bool {
            if (!check(i, i + 1, 0, 9)) return false;
            if (!check(0, 9, j, j + 1)) return false;

            int li = i / 3 * 3, ri = li + 3;
            int lj = j / 3 * 3, rj = lj + 3;
            if (!check(li, ri, lj, rj)) return false;

            return true;
        };

        function<bool(int)> solve = [&board, &is_valid, &solve](int k) -> bool {
            if (k == 81) return true;

            int i = k / 9, j = k % 9;
            if (board[i][j] != '.') return solve(k + 1);

            for (char c = '1'; c <= '9'; ++c) {
                board[i][j] = c;
                if (!is_valid(i, j)) continue;
                if (solve(k + 1)) return true;
            }

            board[i][j] = '.';
            return false;
        };

        solve(0);
    }
};
