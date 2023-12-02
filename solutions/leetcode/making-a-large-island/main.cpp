class Solution {
    const vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        vector<vector<int>> group(m, vector<int>(n, -1));

        function<int(int, int, int)> dfs = [&](int i, int j, int id) -> int {
            if (i < 0 || m <= i || j < 0 || n <= j || grid[i][j] == 0) return 0;
            if (group[i][j] != -1) return 0;
            group[i][j] = id;
            int result = 1;
            for (auto [di, dj] : directions) result += dfs(i + di, j + dj, id);
            return result;
        };

        int result = 1;
        unordered_map<int, int> idToSize;

        for (int i = 0, id = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j, ++id) {
                result = max(result, idToSize[id] = dfs(i, j, id));
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) continue;

                int sz = 1;
                unordered_map<int, bool> vis;

                for (auto [di, dj] : directions) {
                    int ii = i + di;
                    int jj = j + dj;
                    if (ii < 0 || m <= ii || jj < 0 || n <= jj) continue;

                    int id = group[ii][jj];
                    if (vis[id]) continue;
                    vis[id] = true;

                    sz += idToSize[id];
                }

                result = max(result, sz);
            }
        }

        return result;
    }
};
