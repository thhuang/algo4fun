class Solution {
   public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n > size(connections) + 1) return -1;

        vector<vector<int>> graph(n);
        for (auto c : connections)
            graph[c[0]].push_back(c[1]), graph[c[1]].push_back(c[0]);

        vector<bool> vis(n, false);
        function<void(int)> dfs = [&](int u) -> void {
            if (vis[u]) return;
            vis[u] = true;
            for (int v : graph[u]) dfs(v);
        };

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            ++count;
            dfs(i);
        }

        return count - 1;
    }
};

class Solution {
   public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        vector<int> group(n);
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

        for (const auto& c : connections) unite(c[0], c[1]);

        unordered_set<int> networks;
        for (int g : group) networks.insert(find(g));

        return networks.size() - 1;
    }
};
