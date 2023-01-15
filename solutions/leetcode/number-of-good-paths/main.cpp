class Solution {
   public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();

        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> rank(n, 0);
        vector<int> roots(n);
        iota(roots.begin(), roots.end(), 0);

        function<int(int)> find = [&](int x) -> int {
            if (x == roots[x]) return x;
            return roots[x] = find(roots[x]);
        };

        function<void(int, int)> unite = [&](int a, int b) -> void {
            int pa = find(a);
            int pb = find(b);
            if (pa == pb) return;
            if (rank[pa] < rank[pb]) {
                roots[pa] = pb;
            } else if (rank[pb] < rank[pa]) {
                roots[pb] = pa;
            } else {
                roots[pa] = pb;
                ++rank[pb];
            }
        };

        int result = 0;
        map<int, vector<int>> val2nodes;
        for (int u = 0; u < n; ++u) val2nodes[vals[u]].push_back(u);

        for (const auto& [val, nodes] : val2nodes) {
            for (int u : nodes) {
                for (int v : adj[u]) {
                    if (vals[u] < vals[v]) continue;
                    unite(u, v);
                }
            }

            unordered_map<int, int> group_size;
            for (int u : nodes) ++group_size[find(u)];

            for (auto [_, sz] : group_size) {
                result += sz * (sz + 1) / 2;
            }
        }

        return result;
    }
};
