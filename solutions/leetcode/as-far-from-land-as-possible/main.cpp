class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<array<int, 3>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != 1) continue;
                for (auto [di, dj] : directions) q.push({i + di, j + dj, 1});
            }
        }

        int max_dist = 0;
        while (!empty(q)) {
            auto [i, j, d] = q.front();
            q.pop();

            if (i < 0 || i >= n || j < 0 || j >= m) continue;
            if (grid[i][j]) continue;

            ++d;
            grid[i][j] = d;
            max_dist = max(max_dist, d);

            for (auto [di, dj] : directions) {
                q.push({i + di, j + dj, d});
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] > 1) grid[i][j] = 0;
            }
        }

        return max_dist - 1;
    }
};
