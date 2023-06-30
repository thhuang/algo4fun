class Solution {
    const vector<array<int, 2>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

   public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        auto check = [&](int t) -> bool {
            queue<array<int, 2>> q;
            for (int j = 0; j < col; ++j) q.push({0, j});

            vector<vector<bool>> vis(row, vector<bool>(col, false));
            for (int i = 0; i <= t; ++i)
                vis[cells[i][0] - 1][cells[i][1] - 1] = true;

            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop();

                if (i < 0 || row <= i || j < 0 || col <= j) continue;
                if (vis[i][j]) continue;
                vis[i][j] = true;

                if (i == row - 1) return true;

                for (auto [di, dj] : directions) q.push({i + di, j + dj});
            }

            return false;
        };

        int n = cells.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(m)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return l;
    }
};

class Solution {
    const vector<array<int, 2>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

   public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row * col;

        vector<int> rank(n + 2, 0);
        vector<int> group(n + 2);
        iota(group.begin(), group.end(), 0);

        function<int(int)> find = [&](int k) -> int {
            if (k == group[k]) return k;
            return group[k] = find(group[k]);
        };

        function<void(int, int)> unite = [&](int a, int b) -> void {
            int pa = find(a);
            int pb = find(b);
            if (pa == pb) return;
            if (rank[pa] < rank[pb]) {
                group[pa] = pb;
            } else if (rank[pb] < rank[pa]) {
                group[pb] = pa;
            } else {
                group[pb] = pa;
                ++rank[pa];
            }
        };

        vector<bool> water(n + 2, false);
        for (int t = 0; t < n; ++t) {
            int i = cells[t][0] - 1, j = cells[t][1] - 1;
            int u = i * col + j;

            water[u] = true;

            for (auto [di, dj] : directions) {
                int ii = i + di, jj = j + dj;
                if (ii < 0 || row <= ii || jj < 0 || col <= jj) continue;

                int v = ii * col + jj;
                if (!water[v]) continue;

                unite(u, v);
            }

            if (j == 0) {
                unite(u, n);
            } else if (j == col - 1) {
                unite(u, n + 1);
            }

            if (find(n) == find(n + 1)) return t;
        }

        return -1;
    }
};
