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
    array<bool, 9> seen;

   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        auto check = [&](int x, int y, int dx, int dy) -> bool {
            seen.fill(false);
            for (int i = 0; i < dx; ++i) {
                for (int j = 0; j < dy; ++j) {
                    char c = board[x + i][y + j];
                    if (c == '.') continue;
                    int v = c - '1';
                    if (seen[v]) return false;
                    seen[v] = true;
                }
            }
            return true;
        };

        for (int i = 0; i < 9; ++i) {
            if (!check(i, 0, 1, 9)) return false;
            if (!check(0, i, 9, 1)) return false;
            if (!check(i / 3 * 3, i % 3 * 3, 3, 3)) return false;
        }

        return true;
    }
};
