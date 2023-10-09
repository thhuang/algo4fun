class Solution {
    const vector<array<int, 2>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

   public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                     vector<int>& click) {
        int m = board.size();
        int n = board.front().size();

        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        function<int(int, int)> getNum = [&](int i, int j) -> int {
            int result = 0;
            for (auto [di, dj] : directions) {
                int ii = i + di, jj = j + dj;
                if (0 <= ii && ii < m && 0 <= jj && jj < n &&
                    board[ii][jj] == 'M') {
                    ++result;
                }
            }
            return result;
        };

        function<void(int, int)> dfs = [&](int i, int j) -> void {
            if (i < 0 || m <= i || j < 0 || n <= j || board[i][j] != 'E')
                return;
            if (int v = getNum(i, j); v > 0) {
                board[i][j] = '0' + v;
                return;
            }
            board[i][j] = 'B';
            for (auto [di, dj] : directions) {
                dfs(i + di, j + dj);
            }
        };

        dfs(click[0], click[1]);

        return board;
    }
};
