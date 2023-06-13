class Solution {
   public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> edges(n);
        vector<vector<int>> rev_edges(n);
        for (auto c : connections) {
            edges[c[0]].push_back(c[1]);
            rev_edges[c[1]].push_back(c[0]);
        }

        int ans = 0;
        vector<bool> vis(n, false);
        function<void(int, int)> dfs = [&](int u, int cost) -> void {
            if (vis[u]) return;
            vis[u] = true;
            ans += cost;
            for (int v : rev_edges[u]) dfs(v, 0);
            for (int v : edges[u]) dfs(v, 1);
        };

        dfs(0, 0);

        return ans;
    }
};

class Solution {
   public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<array<int, 2>>> adj(n);
        for (vector<int>& c : connections) {
            adj[c[0]].push_back({c[1], 1});
            adj[c[1]].push_back({c[0], 0});
        }

        int result = 0;
        function<void(int, int)> dfs = [&](int u, int p) -> void {
            for (auto [v, c] : adj[u]) {
                if (v == p) continue;
                result += c;
                dfs(v, u);
            }
        };
        dfs(0, 0);

        return result;
    }
};
