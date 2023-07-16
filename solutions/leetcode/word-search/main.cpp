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

class Solution {
    const vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board.front().size();

        string curr;
        function<bool(int, int)> dfs = [&](int i, int j) -> bool {
            if (curr.size() == word.size()) return true;
            if (i < 0 || i >= m || j < 0 || j >= n) return false;
            if (board[i][j] == '-') return false;

            if (int k = curr.size(); board[i][j] != word[k]) return false;

            curr.push_back(board[i][j]);
            board[i][j] = '-';

            int found = false;
            for (auto [di, dj] : directions) {
                if (dfs(i + di, j + dj)) {
                    found = true;
                    break;
                }
            }

            board[i][j] = curr.back();
            curr.pop_back();

            return found;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j)) return true;
            }
        }

        return false;
    }
};

class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board.front().size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        function<bool(int, int, int)> dfs = [&](int i, int j, int k) -> bool {
            if (i < 0 || m <= i || j < 0 || n <= j || vis[i][j] || board[i][j] != word[k]) return false;
            if (k + 1 == word.size()) return true;

            vis[i][j] = true;

            for (auto [di, dj] : directions) {
                if (dfs(i + di, j + dj, k + 1)) return true;
            }

            vis[i][j] = false;

            return false;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j, 0)) return true;
            }
        }

        return false;
    }
};
