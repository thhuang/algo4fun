class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board.front().size();

        function<void(int, int)> dfs = [&](int i, int j) -> void {
            if (i < 0 || i >= n || j < 0 || j >= m) return;
            if (board[i][j] != 'O') return;
            board[i][j] = 'V';
            for (auto [di, dj] : directions) dfs(i + di, j + dj);
        };

        for (int i = 0; i < n; ++i) dfs(i, 0), dfs(i, m - 1);
        for (int j = 0; j < m; ++j) dfs(0, j), dfs(n - 1, j);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'V')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};
