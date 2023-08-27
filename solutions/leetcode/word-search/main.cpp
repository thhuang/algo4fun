class Solution {
    const vector<array<int, 2>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

   public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board.front().size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        function<bool(int, int, int)> search = [&](int i, int j,
                                                   int k) -> bool {
            if (k == word.size()) return true;
            if (i < 0 || m <= i || j < 0 || n <= j || vis[i][j] || word[k] != board[i][j]) return false;
            vis[i][j] = true;

            for (auto [di, dj] : directions) {
                if (search(i + di, j + dj, k + 1)) return true;
            }

            vis[i][j] = false;
            return false;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (search(i, j, 0)) return true;
            }
        }

        return false;
    }
};
