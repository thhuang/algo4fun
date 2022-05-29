class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> q;
        q.push({grid[0][0], 0, 0});

        vector<vector<int>> vis(m, vector<int>(n, m * n + 1));

        while (!q.empty()) {
            auto [c, i, j] = q.top();
            q.pop();

            if (i == m - 1 && j == n - 1) return c;

            for (auto [di, dj] : directions) {
                int ii = i + di, jj = j + dj;
                if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;

                int cc = c + (grid[ii][jj] == 1);
                if (cc >= vis[ii][jj]) continue;
                vis[ii][jj] = cc;

                q.push({cc, ii, jj});
            }
        }

        return 0;
    }
};
