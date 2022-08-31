class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int atlantic = 1;
        const int pacific = 2;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans;

        function<void(int, int, int)> dfs1 = [&](int i, int j, int h) -> void {
            if (i < 0 || i >= n || j < 0 || j >= m) return;
            if (heights[i][j] < h) return;
            if (vis[i][j]) return;
            vis[i][j] = atlantic;
            for (auto [di, dj] : directions)
                dfs1(i + di, j + dj, heights[i][j]);
        };
        for (int i = 0; i < n; ++i) dfs1(i, m - 1, 0);
        for (int j = 0; j < m; ++j) dfs1(n - 1, j, 0);

        function<void(int, int, int)> dfs2 = [&](int i, int j, int h) -> void {
            if (i < 0 || i >= n || j < 0 || j >= m) return;
            if (heights[i][j] < h) return;
            if (vis[i][j] == pacific) return;
            if (vis[i][j] == atlantic) ans.push_back({i, j});
            vis[i][j] = pacific;
            for (auto [di, dj] : directions)
                dfs2(i + di, j + dj, heights[i][j]);
        };
        for (int i = 0; i < n; ++i) dfs2(i, 0, 0);
        for (int j = 0; j < m; ++j) dfs2(0, j, 0);

        return ans;
    }
};

class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    const char unknown = ' ';

   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights.front().size();

        vector<vector<char>> vis(m, vector<char>(n, unknown));

        vector<vector<int>> result;
        function<void(int, int, char)> dfs = [&](int i, int j, char ocean) {
            if (vis[i][j] == ocean) return;
            if (vis[i][j] != unknown) result.push_back({i, j});

            vis[i][j] = ocean;

            for (auto [di, dj] : directions) {
                int ii = i + di;
                int jj = j + dj;
                if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                if (heights[ii][jj] < heights[i][j]) continue;

                dfs(ii, jj, ocean);
            }
        };

        for (int j = 0; j < n; ++j) dfs(0, j, 'p');
        for (int i = 0; i < m; ++i) dfs(i, 0, 'p');
        for (int j = 0; j < n; ++j) dfs(m - 1, j, 'a');
        for (int i = 0; i < m; ++i) dfs(i, n - 1, 'a');

        return result;
    }
};

class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights.front().size();

        vector<vector<int>> region(m, vector<int>(n, 0));

        function<void(int, int, int)> dfs = [&](int i, int j,
                                                int ocean) -> void {
            region[i][j] |= ocean;
            for (auto [di, dj] : directions) {
                int ii = i + di, jj = j + dj;
                if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                if (heights[i][j] > heights[ii][jj]) continue;
                if (region[ii][jj] & ocean) continue;
                dfs(ii, jj, ocean);
            }
        };

        for (int i = 0; i < m; ++i) dfs(i, 0, 1), dfs(i, n - 1, 2);
        for (int j = 0; j < n; ++j) dfs(0, j, 1), dfs(m - 1, j, 2);

        vector<vector<int>> result;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (region[i][j] & 1 && region[i][j] & 2)
                    result.push_back({i, j});

        return result;
    }
};
