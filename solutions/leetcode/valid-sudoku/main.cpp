class Solution {
    array<bool, 9> seen;

   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            seen.fill(false);
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                int v = c - '1';
                if (seen[v]) return false;
                seen[v] = true;
            }

            seen.fill(false);
            for (int j = 0; j < 9; ++j) {
                char c = board[j][i];
                if (c == '.') continue;
                int v = c - '1';
                if (seen[v]) return false;
                seen[v] = true;
            }

            int r = i / 3 * 3;
            int c = i % 3 * 3;
            seen.fill(false);
            for (int x = r; x < r + 3; ++x) {
                for (int y = c; y < c + 3; ++y) {
                    char c = board[x][y];
                    if (c == '.') continue;
                    int v = c - '1';
                    if (seen[v]) return false;
                    seen[v] = true;
                }
            }
        }
        return true;
    }
};

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        function<bool(int, int, int, int)> check = [&](int x, int y, int dx,
                                                       int dy) -> bool {
            vector<bool> seen(9, false);
            for (int i = x; i < x + dx; ++i) {
                for (int j = y; j < y + dy; ++j) {
                    if (board[i][j] == '.') continue;

                    int digit = board[i][j] - '1';
                    if (seen[digit]) return false;
                    seen[digit] = true;
                }
            }
            return true;
        };

        for (int i = 0; i < 9; ++i) {
            if (!check(i, 0, 1, 9)) return false;
            if (!check(0, i, 9, 1)) return false;
            if (!check((i / 3) * 3, (i % 3) * 3, 3, 3)) return false;
        }
        return true;
    }
};
