class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board.front().size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        function<bool(int, int, int)> search = [&](int i, int j,
                                                   int word_idx) -> bool {
            if (i < 0 || i >= n || j < 0 || j >= m) return false;
            if (vis[i][j]) return false;
            if (board[i][j] != word[word_idx]) return false;
            if (word_idx == word.size() - 1) return true;

            vis[i][j] = true;
            for (auto [di, dj] : directions) {
                if (search(i + di, j + dj, word_idx + 1)) return true;
            }
            vis[i][j] = false;

            return false;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (search(i, j, 0)) return true;
            }
        }
        return false;
    }
};
