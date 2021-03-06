class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int n = size(grid);
        int m = size(grid[0]);

        vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        function<void(int, int)> dfs = [&](int i, int j) -> void {
            if (i < 0 || i >= n || j < 0 || j >= m) return;
            if (grid[i][j] != '1') return;

            grid[i][j] = 'v';

            for (auto [di, dj] : directions) dfs(i + di, j + dj);
        };

        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != '1') continue;
                ++count;
                dfs(i, j);
            }
        }

        for (auto& r : grid) {
            for (auto& v : r) {
                v = v == '-' ? '1' : v;
            }
        }

        return count;
    }
};

class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid.front().size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        function<void(int, int)> dfs = [&](int i, int j) -> void {
            if (i < 0 || i >= n || j < 0 || j >= m) return;
            if (grid[i][j] != '1') return;
            if (vis[i][j]) return;
            vis[i][j] = true;
            for (auto [di, dj] : directions) dfs(i + di, j + dj);
        };

        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != '1' || vis[i][j]) continue;
                dfs(i, j);
                ++count;
            }
        }

        return count;
    }
};
