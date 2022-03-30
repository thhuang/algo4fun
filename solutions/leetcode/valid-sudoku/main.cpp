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
