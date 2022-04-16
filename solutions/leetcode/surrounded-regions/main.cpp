class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board.front().size();

        function<void(int, int, char)> dfs = [&](int i, int j,
                                                 char new_val) -> void {
            if (i < 0 || i >= n || j < 0 || j >= m) return;
            if (board[i][j] != 'O') return;
            board[i][j] = new_val;
            for (auto [di, dj] : directions) dfs(i + di, j + dj, new_val);
        };

        for (int i = 0; i < n; ++i) dfs(i, 0, 'V'), dfs(i, m - 1, 'V');
        for (int j = 0; j < m; ++j) dfs(0, j, 'V'), dfs(n - 1, j, 'V');

        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < m - 1; ++j) {
                dfs(i, j, 'X');
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'V') board[i][j] = 'O';
            }
        }
    }
};
