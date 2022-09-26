class Solution {
    int char2index(char c) { return c - 'a'; }

   public:
    bool equationsPossible(vector<string>& equations) {
        array<int, 26> group;
        iota(group.begin(), group.end(), 0);

        function<int(int)> find = [&](int u) -> int {
            if (group[u] == u) return u;
            return group[u] = find(group[u]);
        };

        function<void(int, int)> unite = [&](int u, int v) -> void {
            int pu = find(u);
            int pv = find(v);
            group[pu] = pv;
        };

        for (const auto& e : equations) {
            if (e[1] == '=') unite(char2index(e.front()), char2index(e.back()));
        }

        for (const auto& e : equations) {
            if (e[1] == '!' &&
                find(char2index(e.front())) == find(char2index(e.back())))
                return false;
        }

        return true;
    }
};

class Solution {
   public:
    bool equationsPossible(vector<string>& equations) {
        array<int, 26> group;
        iota(group.begin(), group.end(), 0);

        array<int, 26> sz;
        fill(sz.begin(), sz.end(), 1);

        function<int(int)> find = [&](int u) -> int {
            if (u == group[u]) return u;
            return group[u] = find(group[u]);
        };

        function<void(int, int)> unite = [&](int a, int b) -> void {
            a = find(a);
            b = find(b);
            if (a == b) return;
            if (sz[a] > sz[b]) {
                group[b] = a;
                sz[a] += sz[b];
            } else {
                group[a] = b;
                sz[b] += sz[a];
            }
        };

        for (const string& eq : equations) {
            if (eq[1] == '=') unite(eq[0] - 'a', eq[3] - 'a');
        }

        for (const string& eq : equations) {
            if (eq[1] == '!' && find(eq[0] - 'a') == find(eq[3] - 'a'))
                return false;
        }

        return true;
    }
};
