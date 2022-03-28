class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int n = size(grid1);
        int m = size(grid1[0]);

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        function<bool(int, int)> dfs = [&](int i, int j) -> bool {
            if (i < 0 || i >= n || j < 0 || j >= m) return true;
            if (grid2[i][j] != 1) return true;
            if (vis[i][j]) return true;

            vis[i][j] = true;

            bool result = grid1[i][j] == grid2[i][j];
            for (auto [di, dj] : directions) {
                result &= dfs(i + di, j + dj);
            }
            return result;
        };

        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid2[i][j] != 1 || vis[i][j]) continue;
                if (!dfs(i, j)) continue;
                ++count;
            }
        }

        return count;
    }
};
