class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board.front().size();

        function<void(int, int)> dfs = [&](int i, int j) -> void {
            if (i < 0 || m <= i || j < 0 || n <= j || board[i][j] != 'O') return;
            board[i][j] = 'V';
            for (auto [di, dj] : directions) dfs(i + di, j + dj);
        };

        for (int i = 0; i < m; ++i) dfs(i, 0), dfs(i, n - 1);
        for (int j = 0; j < n; ++j) dfs(0, j), dfs(m - 1, j);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'V') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
