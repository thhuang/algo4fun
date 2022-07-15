class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = size(grid), m = size(grid[0]);

        int max_area = 0;
        function<int(int, int)> search = [&](int i, int j) -> int {
            if (i < 0 || i >= n || j < 0 || j >= m) return 0;
            if (grid[i][j] != 1) return 0;

            grid[i][j] = 2;

            int sum = 1;
            for (auto [di, dj] : directions) {
                sum += search(i + di, j + dj);
            }

            return sum;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                max_area = max(max_area, search(i, j));
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    grid[i][j] = 1;
                }
            }
        }

        return max_area;
    }
};

class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        auto ij2idx = [&](int i, int j) -> int { return i * n + j; };

        vector<int> sz(m * n, 1);
        vector<int> group(m * n);
        iota(group.begin(), group.end(), 0);

        function<int(int)> find = [&](int u) -> int {
            if (u == group[u]) return u;
            return group[u] = find(group[u]);
        };

        function<void(int, int)> unite = [&](int a, int b) -> void {
            int ga = find(a);
            int gb = find(b);
            if (ga == gb) return;
            if (sz[ga] > sz[gb]) {
                group[gb] = ga;
                sz[ga] += sz[gb];
            } else {
                group[ga] = gb;
                sz[gb] += sz[ga];
            }
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    sz[ij2idx(i, j)] = 0;
                    continue;
                }
                for (auto [di, dj] : directions) {
                    int ii = i + di;
                    int jj = j + dj;
                    if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                    if (grid[ii][jj] == 0) continue;
                    unite(ij2idx(i, j), ij2idx(ii, jj));
                }
            }
        }

        return *max_element(sz.begin(), sz.end());
    }
};
