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
