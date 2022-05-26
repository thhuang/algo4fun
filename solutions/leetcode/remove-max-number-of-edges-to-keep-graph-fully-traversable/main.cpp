class Solution {
    class UnionFind {
        vector<int> group;
        int count;

       public:
        UnionFind(int n) : count(n), group(n) {
            iota(group.begin(), group.end(), 0);
        }

        int find(int u) {
            if (u == group[u]) return u;
            return group[u] = find(group[u]);
        }

        bool unite(int u, int v) {
            int pu = find(u);
            int pv = find(v);
            if (pu == pv) return false;

            group[pu] = pv;
            --count;
            return true;
        }

        bool is_united() { return count == 1; }
    };

   public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind alice(n), bob(n);

        int result = 0;

        for (const auto& e : edges) {
            if (e[0] != 3) continue;
            if (!alice.unite(e[1] - 1, e[2] - 1)) ++result;
            bob.unite(e[1] - 1, e[2] - 1);
        }

        for (const auto& e : edges) {
            if (e[0] == 1) {
                if (!alice.unite(e[1] - 1, e[2] - 1)) ++result;
            } else if (e[0] == 2) {
                if (!bob.unite(e[1] - 1, e[2] - 1)) ++result;
            }
        }

        if (alice.is_united() && bob.is_united()) return result;
        return -1;
    }
};
