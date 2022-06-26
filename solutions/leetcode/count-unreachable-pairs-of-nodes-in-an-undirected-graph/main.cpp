class Solution {
   public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> sizes(n, 1);
        vector<int> groups(n);
        iota(groups.begin(), groups.end(), 0);

        function<int(int)> find = [&](int u) -> int {
            if (groups[u] == u) return u;
            return groups[u] = find(groups[u]);
        };

        function<void(int, int)> unite = [&](int u, int v) -> void {
            int pu = find(u);
            int pv = find(v);
            if (pu == pv) return;
            if (sizes[pu] > sizes[pv]) {
                groups[pv] = pu;
                sizes[pu] += sizes[pv];
            } else {
                groups[pu] = pv;
                sizes[pv] += sizes[pu];
            }
        };

        for (const vector<int> e : edges) unite(e[0], e[1]);

        long long result = 0, s = n;
        vector<int> scc;
        for (int i = 0; i < n; ++i) {
            if (i != find(i)) continue;
            result += (s -= sizes[i]) * sizes[i];
        }

        return result;
    }
};
