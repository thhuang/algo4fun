class Solution {
    class UnionFind {
        int cnt;
        vector<int> g, sz;

       public:
        UnionFind(int n) : cnt(n), g(n), sz(n, 1) {
            iota(g.begin(), g.end(), 0);
        }

        int find(int u) {
            if (u == g[u]) return u;
            return g[u] = find(g[u]);
        }

        bool unite(int u, int v) {
            int pu = find(u);
            int pv = find(v);
            if (pu == pv) return cnt == 1;

            --cnt;
            if (sz[pu] > sz[pv]) {
                g[pu] = pv;
                sz[pv] += sz[pu];
            } else {
                g[pv] = pu;
                sz[pu] += sz[pv];
            }
            return cnt == 1;
        }
    };

   public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());

        UnionFind uf(n);

        for (const auto& log : logs) {
            if (uf.unite(log[1], log[2])) return log[0];
        }

        return -1;
    }
};
