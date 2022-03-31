class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        struct Entry {
            int i, j;
            int d;
        };
        queue<Entry> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        function<void(int, int)> dfs = [&](int i, int j) -> void {
            if (vis[i][j]) return;
            vis[i][j] = true;

            for (auto [di, dj] : directions) {
                int ii = i + di, jj = j + dj;
                if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
                if (grid[ii][jj] == 0) {
                    q.push({ii, jj, 1});
                    continue;
                }
                dfs(ii, jj);
            }
        };

        bool found_land = false;
        for (int i = 0; i < n; ++i) {
            if (found_land) break;
            for (int j = 0; j < m; ++j) {
                if (found_land) break;
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    found_land = true;
                }
            }
        }

        while (!empty(q)) {
            auto entry = q.front();
            q.pop();

            int i = entry.i, j = entry.j;
            if (i < 0 || i >= n || j < 0 || j >= m) continue;
            if (vis[i][j]) continue;
            if (grid[i][j] == 1) return entry.d - 1;

            vis[i][j] = true;

            for (auto [di, dj] : directions) {
                int ii = i + di, jj = j + dj;
                q.push({i + di, j + dj, entry.d + 1});
            }
        }

        return 0;
    }
};
