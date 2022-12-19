class Solution {
   public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        function<bool(int)> dfs = [&](int u) -> bool {
            if (vis[u]) return false;
            vis[u] = true;

            if (u == destination) return true;
            for (int v : adj[u]) {
                if (dfs(v)) return true;
            }

            return false;
        };

        return dfs(source);
    }
};
