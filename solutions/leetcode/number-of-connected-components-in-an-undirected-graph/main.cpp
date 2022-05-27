class Solution {
    class UnionFind {
        int n_;
        vector<int> group_;

       public:
        UnionFind(int n) : n_(n), group_(n) {
            iota(group_.begin(), group_.end(), 0);
        }

        void unite(int u, int v) {
            int pu = find(u);
            int pv = find(v);
            if (pu == pv) return;

            group_[pu] = pv;
            --n_;
        }

        int find(int u) {
            if (group_[u] == u) return u;
            return group_[u] = find(group_[u]);
        }

        int components() { return n_; }
    };

   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (const auto& e : edges) uf.unite(e[0], e[1]);
        return uf.components();
    }
};
