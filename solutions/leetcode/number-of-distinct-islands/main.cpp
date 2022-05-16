class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        vector<string> islands;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        function<void(int, int, int, int)> dfs = [&](int i, int j, int pi, int pj) -> void {
            if (i < 0 || i >= m || j < 0 || j >= n) return;
            if (grid[i][j] == 0) return;
            if (vis[i][j]) return;
            vis[i][j] = true;

            islands.back() += to_string(i - pi) + ":" + to_string(j - pj);

            for (auto [di, dj] : directions) dfs(i + di, j + dj, pi, pj);
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 || vis[i][j]) continue;
                islands.push_back("");
                dfs(i, j, i, j);
            }
        }

        return unordered_set<string>(islands.begin(), islands.end()).size();
    }
};
