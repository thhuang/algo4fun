class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        auto rc2idx = [&](int r, int c) -> int { return r * n + c; };

        vector<vector<bool>> mat(m, vector<bool>(n, false));
        vector<int> group(m * n);
        iota(group.begin(), group.end(), 0);

        function<int(int)> find = [&](int u) -> int {
            if (u == group[u]) return u;
            return group[u] = find(group[u]);
        };

        function<void(int, int)> unite = [&](int u, int v) -> void {
            group[find(u)] = find(v);
        };

        vector<int> result(positions.size());
        int count = 0;
        for (int k = 0; k < positions.size(); ++k) {
            int i = positions[k][0];
            int j = positions[k][1];

            if (mat[i][j]) {
                result[k] = count;
                continue;
            }
            mat[i][j] = true;

            unordered_set<int> g;
            for (auto [di, dj] : directions) {
                int ii = i + di, jj = j + dj;
                if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                if (!mat[ii][jj]) continue;
                g.insert(find(rc2idx(ii, jj)));
            }

            int u = rc2idx(i, j);
            for (int v : g) unite(u, v);

            count += 1 - g.size();
            result[k] = count;
        }

        return result;
    }
};
