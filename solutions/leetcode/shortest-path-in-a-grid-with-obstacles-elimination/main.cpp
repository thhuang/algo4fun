class Solution {
    const vector<pair<int, int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

   public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid.front().size();

        vector<vector<vector<int>>> vis(
            m, vector<vector<int>>(
                   n, vector<int>(k + 1, numeric_limits<int>::max())));

        queue<array<int, 4>> q;  // {i, j, steps, k remain}
        q.push({0, 0, 0, k});

        while (!q.empty()) {
            auto [i, j, steps, k_remain] = q.front();
            q.pop();

            if (i == m - 1 && j == n - 1) return steps;

            if (steps >= vis[i][j][k_remain]) continue;
            vis[i][j][k_remain] = steps;

            for (auto [di, dj] : directions) {
                int ii = i + di;
                int jj = j + dj;
                int kk = k_remain;
                if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                if (grid[ii][jj] == 1) --kk;
                if (kk < 0) continue;
                q.push({ii, jj, steps + 1, kk});
            }
        }

        int result = numeric_limits<int>::max();
        for (int v : vis.back().back()) result = min(result, v);

        if (result == numeric_limits<int>::max()) return -1;
        return result;
    }
};
