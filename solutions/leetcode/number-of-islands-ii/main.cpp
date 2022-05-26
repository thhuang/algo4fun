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
            int pu = find(u);
            int pv = find(v);
            group[pu] = pv;
        };

        vector<int> result;
        int count = 0;
        for (const auto p : positions) {
            if (mat[p[0]][p[1]]) {
                result.push_back(count);
                continue;
            }

            unordered_set<int> g;
            for (auto [di, dj] : directions) {
                int i = p[0] + di;
                int j = p[1] + dj;
                if (i < 0 || i >= m || j < 0 || j >= n) continue;
                if (!mat[i][j]) continue;
                g.insert(find(rc2idx(i, j)));
            }

            int u = rc2idx(p[0], p[1]);
            for (int v : g) unite(u, v);

            mat[p[0]][p[1]] = true;

            count += 1 - g.size();
            result.push_back(count);
        }

        return result;
    }
};
