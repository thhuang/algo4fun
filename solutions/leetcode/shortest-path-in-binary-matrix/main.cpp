class Solution {
    vector<array<int, 2>> directions = {{1, 1},  {1, 0},  {1, -1}, {0, 1},
                                        {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

   public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = size(grid);
        int m = size(grid[0]);
        int base = 10;

        struct Entry {
            int i, j;
            int d;
        };

        int ans = -1;
        queue<Entry> q;
        q.push({0, 0, base + 1});
        while (!empty(q)) {
            auto e = q.front();
            q.pop();

            if (e.i < 0 || e.i >= n || e.j < 0 || e.j >= m) continue;
            if (grid[e.i][e.j] != 0) continue;

            grid[e.i][e.j] = e.d;

            if (e.i == n - 1 && e.j == m - 1) {
                ans = e.d - base;
                break;
            }

            for (auto [di, dj] : directions)
                q.push({e.i + di, e.j + dj, e.d + 1});
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] >= 10) grid[i][j] = 0;
            }
        }

        return ans;
    }
};

class Solution {
    vector<array<int, 2>> directions = {{1, 1},  {1, 0},  {1, -1}, {0, 1},
                                        {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

   public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.front().size();

        int step = 1;
        vector<array<int, 2>> q = {{0, 0}};
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        while (!q.empty()) {
            vector<array<int, 2>> new_q;
            for (auto [i, j] : q) {
                if (i < 0 || i >= n || j < 0 || j >= m) continue;
                if (grid[i][j] == 1) continue;
                if (i == n - 1 && j == m - 1) return step;
                if (vis[i][j]) continue;
                vis[i][j] = true;
                for (auto [di, dj] : directions)
                    new_q.push_back({i + di, j + dj});
            }
            q = move(new_q);
            ++step;
        }

        return -1;
    }
};
