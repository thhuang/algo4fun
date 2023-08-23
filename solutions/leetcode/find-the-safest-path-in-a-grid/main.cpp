class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        vector<vector<int>> mat(m, vector<int>(n, numeric_limits<int>::max()));
        queue<array<int, 3>> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1) q.push({i, j, 0});

        while (!q.empty()) {
            auto [i, j, d] = q.front();
            q.pop();

            if (i < 0 || m <= i || j < 0 || n <= j || mat[i][j] <= d) continue;
            mat[i][j] = d;

            for (auto [di, dj] : directions) {
                q.push({i + di, j + dj, d + 1});
            }
        }

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        priority_queue<array<int, 3>> pq;
        pq.push({mat[0][0], 0, 0});

        while (!pq.empty()) {
            auto [v, i, j] = pq.top();
            pq.pop();

            if (i == m - 1 && j == n - 1) return v;

            for (auto [di, dj] : directions) {
                int ii = i + di;
                int jj = j + dj;
                if (ii < 0 || m <= ii || jj < 0 || n <= jj || vis[ii][jj])
                    continue;
                vis[ii][jj] = true;
                pq.push({min(v, mat[ii][jj]), ii, jj});
            }
        }

        return -1;
    }
};
