class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board.front().size();

        int result = 0;

        function<void(int, int)> dfs = [&](int i, int j) -> void {
            if (i < 0 || m <= i || j < 0 || n <= j || board[i][j] != 'X')
                return;
            board[i][j] = 'O';
            for (auto [di, dj] : directions) dfs(i + di, j + dj);
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != 'X') continue;
                dfs(i, j);
                ++result;
            }
        }

        return result;
    }
};
