class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> rank(n, 0);
        vector<int> group(n);
        iota(group.begin(), group.end(), 0);

        function<int(int)> find = [&](int u) -> int {
            if (group[u] == u) return u;
            return group[u] = find(group[u]);
        };

        function<bool(int, int)> unite = [&](int u, int v) -> bool {
            int gu = find(u);
            int gv = find(v);
            if (gu == gv) {
                return false;
            }
            if (rank[gu] < rank[gv]) {
                group[gu] = gv;
            } else if (rank[gv] < rank[gu]) {
                group[gv] = gu;
            } else {
                group[gu] = gv;
                ++rank[gv];
            }
            return true;
        };

        for (const auto& e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            if (!unite(u, v)) return e;
        }

        return {};
    }
};
