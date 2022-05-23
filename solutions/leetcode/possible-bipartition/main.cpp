class Solution {
   public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        for (const auto& d : dislikes) {
            adj[d[0] - 1].push_back(d[1] - 1);
            adj[d[1] - 1].push_back(d[0] - 1);
        }

        vector<int> vis(n, -1);

        function<bool(int, int)> dfs = [&](int u, int group) -> bool {
            if (vis[u] != -1) return vis[u] == group;
            vis[u] = group;
            for (int v : adj[u]) {
                if (!dfs(v, !group)) return false;
            }
            return true;
        };

        for (int i = 0; i < n; ++i) {
            if (vis[i] != -1) continue;
            if (!dfs(i, 0)) return false;
        }

        return true;
    }
};
